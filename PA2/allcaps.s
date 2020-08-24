/*
* Filename: allcaps.s
* Author: Kunal Singla
* UserId: CSE30S220EQ
* Date: 08/23/2020
* Sources of help: Lecture Slides, Piazza
*/

@ Describe the hardware to the assembler
	.arch	armv6
	.cpu    cortex-a53
	.syntax unified

@ Declare any external functions
	.extern putchar
	.global main

@ Define any constants
	.equ 	FP_OFFSET, 4
	.equ 	EXIT_SUCCESS, 0
	.equ 	CAPS_SUB_FACTOR, 32
	.equ 	NULL_TERMINATOR, 0x0
	.equ	LOWER_CASE_A, 0x61
	.equ	LOWER_CASE_Z, 0x7A

@ Start data segment where you will define your string
	.section .rodata
mesg:	.asciz	"Hello World!"

	.text
	.type	main, %function

/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!! IMPORTANT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  */
/* You MUST name the string you will convert as "mesg" (without the quotes) */
/* Also, do NOT have any spaces between "mesg" and ":" when defining your   */ 
/* string. It should look like "mesg:" exactly.                             */

@ Start text segment and begin writing your function

/*
* Registers used:
*   <register> - <use> -- <description of what the value represents>
* example:
*   r0 - arg 1 -- number of values to add together
*   r1 - arg 2 -- starting value to start adding from
*   r2 - local var -- keeps track of loop index
*
* Stack variables:
*   < name> - <fp offset> -- <description of what the value represents>
* example:
*   sum - [fp - 8] -- holds the sum of values
*/

@r0-r3 temp registers
@r4+ non-temp registers

main:
	/* PROLOGUE */
	push	{fp, lr}
	add	fp, sp, FP_OFFSET

	/* START OF MAIN PROGRAM */
	ldr	r4, =mesg		@ load mesg into r4 (non-temp) register
	ldrb	r0, [r4]		@ load byte into r1 (temp) register
	cmp	r0, NULL_TERMINATOR	@ check if empty string
	beq	epilogue
loop:
	cmp	r0, LOWER_CASE_A 	@ compare char to lower case a
	blt	next_char		@ if less than 'a', go to next char
	cmp	r0, LOWER_CASE_Z	@ compare char to lower case z
	bgt	next_char		@ if greater than 'z', go to next char
	sub	r0, r0, CAPS_SUB_FACTOR @ between 'a' and 'z', make uppercase
next_char:
	bl	putchar			@ print char to terminal
	add	r4, r4, 1		@ increment register "index"
	ldrb	r0, [r4]		@ load next char (byte) into r1 (temp)
	cmp	r0, NULL_TERMINATOR	@ check if end of string
	bne	loop			@ go to loop again if not end of string
	/* END OF MAIN PROGRAM */

epilogue:
	/* EPILOGUE */
	mov	r0, EXIT_SUCCESS
	sub	sp, fp, FP_OFFSET
	pop	{fp, lr}
	bx	lr
.end
