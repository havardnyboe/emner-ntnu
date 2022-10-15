.thumb
.syntax unified

.include "gpio_constants.s"     // Register-adresser og konstanter for GPIO
.include "sys-tick_constants.s" // Register-adresser og konstanter for SysTick

.text
	.global Start
	
Start:

    LDR R10, =tenths
    LDR R11, =seconds
    LDR R12, =minutes

    MOV R0, 0b0101

    B LOOP

LOOP:

    STR R0, [R10]
    STR R0, [R11]
    STR R0, [R12]

    B LOOP


BEGIN_TIMER:



    B BEGIN_TIMER


PAUSE_TIMER:



    B PAUSE_TIMER


NOP // Behold denne på bunnen av fila

