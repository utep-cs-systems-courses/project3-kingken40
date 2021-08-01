	#include "switches.h"
	#include "stateMachines.h"
	#include "lcdutils.h"
	#include "lcddraw.h"

	.arch msp430g2553
	.p2align 1,0

	.text
	.global state_advance
	.global state
	.extern shape_red
	.extern shape_blue
	.extern shape_white
	.extern shape_yellow
	.extern clearScreen
	.extern COLOR_RED
	.extern COLOR_BLUE
	.extern COLOR_WHITE
	.extern COLOR_YELLOW

	
	.data

	.extern myColor

	
state:
	.word 0
jt:
	.word case_1
	.word case_2
	.word case_3
	.word case_4


state_advance:
	mov &state, r12		;MOVES STATE INTO REGISTER 12
	add r12, r12		;DOUBLE FOR WORDS IN SEQUENCE
	mov jt(r12), r0		;INDEXES JT TABLE IN REGISTER 0

case_1:
	mov #COLOR_GREEN, r12	;COLOR_GREEN FIRST PARAM
	call #clearScreen
	call #shape_red
	jmp end

case_2:
	mov #COLOR_GREEN, r12
	call #clearScreen
	call #shape_blue
	jmp end

case_3:
	mov #COLOR_GREEN, r12
	call #clearScreen
	call #shape_white
	jmp end

case_4:
	mov #COLOR_GREEN, r12
	call #clearScreen
	call #shape_yellow
	jmp end

end:
	pop r0			;RETI
