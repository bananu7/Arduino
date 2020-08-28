.section .text
.global _start

.equ    UART0,	0x09000000
.equ	DELAY,	100000000

_start:
	ldr r0, ='B'
	ldr r1, =UART0
	str r0, [r1]
	bl .delay
	b _start

.delay:
	ldr r2, =DELAY
1:
	subs r2, #1
	bne 1b

	bx lr

.data
	delay_ticks: .word 0xffffffff
