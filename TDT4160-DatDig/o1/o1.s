.thumb
.syntax unified

.include "gpio_constants.s"     // Register-adresser og konstanter for GPIO

.text
	.global Start
	
Start:

	LDR R0, =PORT_E    // finner offset til PORT E
	LDR R1, =PORT_SIZE // finner offstt til hele porten
	MUL R0, R0, R1     // regner ut total offset til PORT E (avstanden mellom GPIO_BASE og PORT E i bits)
	LDR R1, =GPIO_BASE // finner GPIO base-adresse
	ADD R0, R0, R1     // laster R0 med adressen til PORT E

	MOV R2, #1                 // laster tallet 1 til register R2
	LSL R2, R2, #LED_PIN       // bit-shifter 0b00000001 til 0b00000100
	LDR R1, =GPIO_PORT_DOUTSET // finner offset til "Set data output"
	STR R2, [R0, R1]           // lagre R2 (0b00000100) på minnelokasjon R0 + R1 (PORT E address + DOUTSET) 

NOP // Behold denne på bunnen av fila
