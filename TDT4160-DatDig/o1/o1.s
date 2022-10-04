.thumb
.syntax unified

.include "gpio_constants.s"     // Register-adresser og konstanter for GPIO

.text
	.global Start
	
Start:

	LDR R1, = BUTTON_PORT  // finner offset til PORT B
	LDR R0, =PORT_SIZE 	   // finner offstt til hele porten
	MUL R1, R1, R0
	LDR R0, =GPIO_BASE
	ADD R1, R1, R0

	LDR R3, =GPIO_PORT_DIN // finner offset til "Data input"
	ADD R3, R3, R1

	LDR R1, =LED_PORT  // finner offset til PORT E
	LDR R0, =PORT_SIZE // finner offstt til hele porten
	MUL R1, R1, R0     // regner ut total offset til PORT E (avstanden mellom GPIO_BASE og PORT E i bits)
	LDR R0, =GPIO_BASE // finner GPIO base-adresse
	ADD R1, R1, R0     // laster R1 med adressen til PORT E

	LDR R4, =GPIO_PORT_DOUTSET // finner offset til "Set data output"
	ADD R4, R4, R1
	LDR R5, =GPIO_PORT_DOUTCLR // finner offset til "Clear data output"
	ADD R5, R5, R1
	
	MOV R10, #1                    // laster tallet 1 til register R10
	LSL R10, R10, LED_PIN		   // bit-shifter til LED pinen (?)
	
	B LOOP

LOOP:

	LDR R1, [R3]
	MOV R0, #1
	LSL R0, R0, BUTTON_PIN
	AND R2, R1, R0
	CMP R2, 0

	BEQ TURNON

	B TURNOFF

TURNON:

	STR R10, [R4]
	B LOOP

TURNOFF:

	STR R10, [R5]
	B LOOP

NOP // Behold denne på bunnen av fila
