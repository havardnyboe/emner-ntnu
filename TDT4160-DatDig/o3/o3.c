#include "o3.h"
#include "gpio.h"
#include "systick.h"

/******************************************************************************
 * @brief Konverterer nummer til string
 * Konverterer et nummer mellom 0 og 99 til string
 *****************************************************************************/
void int_to_string(char *timestamp, unsigned int offset, int i) {
    if (i > 99) {
        timestamp[offset] = '9';
        timestamp[offset + 1] = '9';
        return;
    }

    while (i > 0) {
        if (i >= 10) {
            i -= 10;
            timestamp[offset]++;

        } else {
            timestamp[offset + 1] = '0' + i;
            i = 0;
        }
    }
}

/******************************************************************************
 * @brief Konverterer 3 tall til en timestamp-string
 * timestamp-argumentet må være et array med plass til (minst) 7 elementer.
 * Det kan deklareres i funksjonen som kaller som "char timestamp[7];"
 * Kallet blir dermed:
 * char timestamp[7];
 * time_to_string(timestamp, h, m, s);
 *****************************************************************************/
void time_to_string(char *timestamp, int h, int m, int s) {
    timestamp[0] = '0';
    timestamp[1] = '0';
    timestamp[2] = '0';
    timestamp[3] = '0';
    timestamp[4] = '0';
    timestamp[5] = '0';
    timestamp[6] = '\0';

    int_to_string(timestamp, 0, h);
    int_to_string(timestamp, 2, m);
    int_to_string(timestamp, 4, s);
}

typedef struct {
    volatile word CTRL;
    volatile word MODEL;
    volatile word MODEH;
    volatile word DOUT;
    volatile word DOUTSET;
    volatile word DOUTCLR;
    volatile word DOUTTGL;
    volatile word DIN;
    volatile word PINLOCKN;
} gpio_port_map_t;

typedef struct {
    volatile gpio_port_map_t ports[6];
    volatile word unused_space[10];
    volatile word EXTIPSELL;
    volatile word EXTIPSELH;
    volatile word EXTIRISE;
    volatile word EXTIFALL;
    volatile word IEN;
    volatile word IF;
    volatile word IFS;
    volatile word IFC;
    volatile word ROUTE;
    volatile word INSENSE;
    volatile word LOCK;
    volatile word CTRL;
    volatile word CMD;
    volatile word EM4WUEN;
    volatile word EM4WUPOL;
    volatile word EM4WUCAUSE;
} gpio_map_t;

typedef struct {
    volatile word CTRL;
    volatile word LOAD;
    volatile word VAL;
    volatile word CALIB;
} systick_t;

#define LED_PIN 2
#define BTN1_PIN 9
#define BTN2_PIN 10
#define LED_PORT GPIO_PORT_E
#define BTN_PORT GPIO_PORT_B

enum state {
    SECONDS,
    MINUTES,
    HOURS,
    COUNTDOWN,
    ALARM
};

// Globale variabler
volatile gpio_map_t *gpio;
volatile systick_t *sys_tick;
enum state state;
int seconds, minutes, hours;

void lightLED(bool turnOn) {
    if (turnOn) {
        gpio->ports[LED_PORT].DOUTSET = 0b0001 << LED_PIN;
    } else {
        gpio->ports[LED_PORT].DOUTCLR = 0b0001 << LED_PIN;
    }
}

void GPIO_ODD_IRQHandler(void) {
    switch (state) {
    case SECONDS:
        seconds == 59 ? seconds = 0, minutes++ : seconds++;
        break;
    case MINUTES:
        minutes == 59 ? minutes = 0, hours++ : minutes++;
        break;
    case HOURS:
        HOURS == 99 ? hours : hours++;
        break;
    default:
        break;
    }

    gpio->IFC = 1 << BTN1_PIN;
}

void GPIO_EVEN_IRQHandler(void) {
    switch (state) {
    case COUNTDOWN:
        break;
    case ALARM:
        state = SECONDS;
        lightLED(false);
        break;
    default:
        state++;
        break;
    }

    gpio->IFC = 1 << BTN2_PIN;
}

void SysTick_Handler(void) {
    switch (state) {
    case COUNTDOWN:
        seconds--;
        if (hours == 0 && minutes == 0 && seconds == 0) {
            state = ALARM;
            lightLED(true);
        }
        if (seconds == -1) {
            minutes--;
            seconds = 59;
            if (minutes == -1) {
                hours--;
                minutes = 59;
            }
        }
        break;
    default:
        break;
    }
}

int main(void) {
    init();

    // setup SysTick
    sys_tick = (systick_t *)SYSTICK_BASE;
    sys_tick->CTRL = 0b0111;
    sys_tick->LOAD = FREQUENCY;

    // setup LED
    gpio = (gpio_map_t *)GPIO_BASE;
    gpio->ports[LED_PORT].MODEL = ((~(0b1111 << 8)) & gpio->ports[LED_PORT].MODEL) | (GPIO_MODE_OUTPUT << 8);

    // setup BTN1 with interrupt
    gpio->ports[BTN_PORT].MODEH = ((~(0b1111 << 4)) & gpio->ports[BTN_PORT].MODEH) | (GPIO_MODE_INPUT << 4);
    gpio->EXTIPSELH = ((~(0b1111 << 4)) & gpio->EXTIPSELH) | (0b0001 << 4);
    gpio->EXTIFALL = gpio->EXTIFALL | (1 << BTN1_PIN);
    gpio->IFC = gpio->IFC | (1 << BTN1_PIN);
    gpio->IEN = gpio->IEN | (1 << BTN1_PIN);

    // setup BTN2 with interrupt
    gpio->ports[BTN_PORT].MODEH = ((~(0b1111 << 8)) & gpio->ports[BTN_PORT].MODEH) | (GPIO_MODE_INPUT << 8);
    gpio->EXTIPSELH = ((~(0b1111 << 8)) & gpio->EXTIPSELH) | (0b0001 << 8);
    gpio->EXTIFALL = gpio->EXTIFALL | (1 << BTN2_PIN);
    gpio->IFC = gpio->IFC | (1 << BTN2_PIN);
    gpio->IEN = gpio->IEN | (1 << BTN2_PIN);

    // default display
    seconds = 0;
    minutes = 0;
    hours = 0;
    state = SECONDS; // start in SECONDS state

    while (true) {
        char output[7];
        time_to_string(output, hours, minutes, seconds);
        lcd_write(output);
    }

    return 0;
}
