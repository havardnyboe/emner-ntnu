.thumb
.syntax unified

.include "gpio_constants.s"     // Register-adresser og konstanter for GPIO

.text
	.global Start
	
Start:

    LDR R0, =PORT_E
	LDR R1, =PORT_SIZE
	MUL R0, R0, R1
	LDR R1, =GPIO_BASE
	ADD R0, R0, R1

	MOV R2, #1
	LSL R2, R2, #LED_PIN
	LDR R1, =GPIO_PORT_DOUTSET
	STR R2, [R0, R1]


NOP // Behold denne på bunnen av fila

