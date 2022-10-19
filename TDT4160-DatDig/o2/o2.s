.thumb
.syntax unified

.include "gpio_constants.s"     // Register-adresser og konstanter for GPIO
.include "sys-tick_constants.s" // Register-adresser og konstanter for SysTick

.text
	.global Start
	
Start:

	// Setter opp SysTick
	LDR R0, =SYSTICK_BASE    // SysTick Control og Status register
	MOV R1, 0b000            // CLKSOURCE, TICKINT og ENABLE bits settes til 0 (starter pauset)
	STR R1, [R0]
    ADD R1, R0, SYSTICK_LOAD // Reload Value Register
    ADD R2, R0, SYSTICK_VAL  // Current Value Register
	LDR R0, =1400000         // Frequency / 10
	STR R0, [R1]
	STR R0, [R2]

	// Finner GPIO offsets og laster knapp og LED til register
	LDR R0, =PORT_SIZE
    LDR R1, =LED_PORT
	MUL R1, R1, R0

	LDR R0, =GPIO_BASE
	ADD R4, R0, GPIO_IFC       // R4 = Interrupt Flag Clear (adresse)

	ADD R1, R1, R0
	LDR R5, =GPIO_PORT_DOUTSET
	ADD R5, R5, R1             // R5 = LED_SET (adresse)
	LDR R6, =GPIO_PORT_DOUTCLR
	ADD R6, R6, R1             // R6 = LED_CLR (adresse)

	MOV R1, 0b1111
	LSL R1, R1, 4
	MVN R1, R1
	ADD R2, R0, GPIO_EXTIPSELH
	LDR R3, [R2]
	AND R3, R3, R1
	MOV R1, BUTTON_PORT
	LSL R1, R1, 4
	ORR R3, R3, R1
	STR R3, [R2]               // BUTTON_PORT er satt til interrupt

	ADD R2, R0, GPIO_EXTIFALL
	LDR R3, [R2]
	MOV R1, #1
	LSL R1, R1, BUTTON_PIN
	ORR R3, R3, R1
	STR R3, [R2]               // fallende flanke er satt på BUTTON_PIN
	ADD R2, R0, GPIO_IEN
	STR R3, [R2]               // enabled interrupt på BUTTON_PIN

	// Laster tenths, seconds og minutes til register
    MOV R7, #0
    MOV R8, #0
    MOV R9, #0
    LDR R10, =tenths
    LDR R11, =seconds
    LDR R12, =minutes

	// R4-R12 er nå reservert, R0-R3 kan brukes fritt
	B LOOP

LOOP: // tom loop for at programmet skal jobbe med noe

	B LOOP

.global GPIO_ODD_IRQHandler
.thumb_func
GPIO_ODD_IRQHandler:

	LDR R0, =SYSTICK_BASE
	LDR R1, [R0]
	CMP R1, 0b000 // if SYSTICK_BASE == 0b000 (programmet er pauset)
	BEQ RESUME    // goto RESUME
                  // else:
	MOV R1, 0b000
	STR R1, [R0]  // sett SYSTICK_BASE = 0b000 (pause programmet)
	B IF_CLEAR

	BX LR

.global SysTick_Handler
.thumb_func
SysTick_Handler:    // interrupt hvert tiendels sekund

	B INC_TENTHS

	BX LR

INC_TENTHS:

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

IF_CLEAR:

	MOV R0, #1
	LSL R0, R0, BUTTON_PIN
	STR R0, [R4]           // renser interrupt flag

	BX LR

RESUME:

	LDR R0, =SYSTICK_BASE
	MOV R1, 0b111
	STR R1, [R0]           // setter SYSTICK_BASE = 0b111 (enable SysTick)

	B IF_CLEAR

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
