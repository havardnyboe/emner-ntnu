.thumb
.syntax unified

.include "gpio_constants.s"     // Register-adresser og konstanter for GPIO

.text
	.global Start
	
Start:

	LDR R1, =LED_PORT  	  // finner offset til PORT E
	LDR R2, = BUTTON_PORT // finner offset til PORT B
	LDR R0, =PORT_SIZE 	  // finner offstt til hele porten
	MUL R1, R1, R0        // regner ut total offset til PORT E (avstanden mellom GPIO_BASE og PORT E i bits)
	MUL R2, R2, R0        // regner ut total offset til PORT B (avstanden mellom GPIO_BASE og PORT B i bits)
	LDR R0, =GPIO_BASE    // finner GPIO base-adresse
	ADD R1, R1, R0        // laster R1 med adressen til PORT E
	ADD R2, R2, R0        // laster R2 med adressen til PORT B

	LDR R3, =GPIO_PORT_DIN 	   // finner offset til "Data input"
	ADD R3, R3, R2
	LDR R4, =GPIO_PORT_DOUTSET // finner offset til "Set data output"
	ADD R4, R4, R1
	LDR R5, =GPIO_PORT_DOUTCLR // finner offset til "Clear data output"
	ADD R5, R5, R1
	
	MOV R10, #1           // laster tallet 1 til register R10
	LSL R10, R10, LED_PIN // bit-shifter til LED pinen
	
	B LOOP

LOOP:

	LDR R1, [R3]           // les fra knapp
	MOV R0, #1             // laster 1 til R0
	LSL R0, R0, BUTTON_PIN // bit-shifter til BUTTON pinen
	AND R2, R1, R0         // bit-wise AND på data fra knapp og R0, lagrer til R2
	CMP R2, 0              // sammenlign R2 med 0, knapp er aktiv lav, hvis de er like settes Z = 1

	BEQ TURNON  // branch hvis verdiene er like, (Z flagg er 1)
	BNE TURNOFF // branch hvis verdiene ikke er like, (Z flagg er 0)

TURNON:

	STR R10, [R4] // last magitallet til DOUTSET
	B LOOP

TURNOFF:

	STR R10, [R5] // last magitallet til DOUTCLR
	B LOOP

NOP // Behold denne på bunnen av fila
