.thumb
.syntax unified

.include "gpio_constants.s"     // Register-adresser og konstanter for GPIO
.include "sys-tick_constants.s" // Register-adresser og konstanter for SysTick

.text
	.global Start
	
Start:

	// Setter opp SysTick
	LDR R0, =SYSTICK_BASE    // Control and Status register
	MOV R1, 0b111            // CLKSOURCE, TICKINT og ENABLE bits settes til 1
	STR R1, [R0]
    ADD R1, R0, SYSTICK_LOAD // Reload Value Register
    ADD R2, R0, SYSTICK_VAL  // Current Value Register
	LDR R0, =1400000         // Frequency / 10
	STR R0, [R1]
	STR R0, [R2]
	// Setter opp GPIO interrupt handler

	// Finner GPIO offsets og laster knapp og LED til register
    LDR R1, =LED_PORT
	LDR R2, =BUTTON_PORT
	LDR R0, =PORT_SIZE
	MUL R1, R1, R0
	MUL R2, R2, R0
	LDR R0, =GPIO_BASE
	ADD R1, R1, R0
	ADD R2, R2, R0
	LDR R4, =GPIO_PORT_DIN
	ADD R4, R4, R2             // R4 = BTN0 (adress)
	LDR R5, =GPIO_PORT_DOUTSET
	ADD R5, R5, R1             // R5 = LED_SET (adress)
	LDR R6, =GPIO_PORT_DOUTCLR
	ADD R6, R6, R1             // R6 = LED_CLR (adress)
	// Laster tenths, seconds og minutes til register
    MOV R7, #0
    MOV R8, #0
    MOV R9, #0
    LDR R10, =tenths
    LDR R11, =seconds
    LDR R12, =minutes

	// R4-R12 er nå reservert, R0-R3 kan brukes fritt

	B LOOP

LOOP:

	// les knapp
	// if BTN is PRESSED
	//     interrupt and pause timer

	B LOOP


.global GPIO_ODD_IRQHandler
.thumb_func
GPIO_ODD_IRQHandler:
    


	BX LR


.global SysTick_Handler
.thumb_func
SysTick_Handler:    // interrupt hvert tiendels sekund

	ADD R7, R7, #1  // tenths++ 
	CMP R7, #10     // if tenths == 10
	BEQ INC_SECONDS // goto increment seconds

	STR R7, [R10]   // laster tenths med verdien til tenths 

	BX LR


INC_SECONDS:

	MOV R7, #0
	STR R7, [R10]   // reseter tenths til 0
	ADD R8, R8, #1  // seconds++
	CMP R8, #60     // if seconds == 60
	BEQ INC_MINUTES // goto increment minutes

	STR R8, [R11]   // laster seconds med verdien til seconds

	MOV R0, R8
	AND R0, R0, #1  // bitwise and for å separere siste bit
	CMP R0, #1      // hvis siste bit er 1 er det oddetall, elles partall
	BEQ TURNON
	B TURNOFF

	BX LR

INC_MINUTES:

	MOV R8, #0
	STR R8, [R11]   // reseter seconds til 0
	ADD R9, R9, #1  // minutes++
	
	STR R9, [R12]   // last minutes med verdien til minutes

	BX LR


READ_BTN:

    LDR R1, [R4]           // leser inn fra knapp
	MOV R0, #1
	LSL R0, R0, BUTTON_PIN // bit-shifter til BUTTON pinen
	AND R2, R1, R0         // bit-wise AND på data fra knapp og R0, lagrer til R2

    BX LR


TURNON:

	MOV R0, #1
	LSL R0, R0, LED_PIN // bit-shifter til LED pinen
	STR R0, [R5]        // laster PIN tallet til DOUTSET

	BX LR


TURNOFF:

	MOV R0, #1
	LSL R0, R0, LED_PIN // bit-shifter til LED pinen
	STR R0, [R6]        // last PIN tallet til DOUTCLR

	BX LR



NOP // Behold denne på bunnen av fila

