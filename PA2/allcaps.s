/*
* Filename: allcaps.s
* Author: Kunal Singla
* UserId: CSE30S220EQ
* Date: 08/23/2020
* Sources of help: Lecture Slides, Piazza, Tutors
*/

@ Hardware Description
	.arch	armv6
	.cpu    cortex-a53
	.syntax unified

@ Functions
	.extern putchar                 @ function to write a char to stdout
	.global main                    @ defining global main function

@ Constants
	.equ 	FP_OFFSET, 4            @ fp offset in simple frame
	.equ 	EXIT_SUCCESS, 0         @ value for successful ending of program
	.equ 	CAPS_SUB_FACTOR, 32     /* factor for converting lower case to
                                           upper case */
	.equ 	NULL_TERMINATOR, 0x0    /* Null terminator character '\0' for
                                           detecting end of string */
	.equ	LOWER_CASE_A, 0x61      @ ASCII value in hex for lower case a
	.equ	LOWER_CASE_Z, 0x7A      @ ASCII value in hex for lower case z

@ Data segment
	.section .rodata
mesg:	.asciz	"hello world!"          @ mesg label for string to manipulate

	.text
	.type	main, %function         @ indication that main is a function

/*
* Function Name: main
* Function prototype: main:
* Description: The main function runs the program to modify any lower case
*              letters in a string into uppercase.
* Side Effects: prints "lower-cased" string to standard out
* Error Conditions: None
* Return Value: None
* Registers used:
*   <register> - <use> -- <description of what the value represents>
* example:
*   r0 - char -- stores current char of string
*   r4 - string -- stores the string pointer
*/

main:
	/* PROLOGUE */
	push	{fp, lr}                @ stack frame register save
	add	fp, sp, FP_OFFSET       @ locate our frame pointer

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
	add	r4, r4, 1		@ increment register "index" by 1
	ldrb	r0, [r4]		@ load next char (byte) into r1 (temp)
	cmp	r0, NULL_TERMINATOR	@ check if end of string
	bne	loop			@ go to loop again if not end of string
	/* END OF MAIN PROGRAM */

epilogue:
	/* EPILOGUE */
	mov	r0, EXIT_SUCCESS        @ set return to EXIT_SUCCESS
	sub	sp, fp, FP_OFFSET       @ restore stack frame top
	pop	{fp, lr}                @ remove stack frame and restore
	bx	lr                      @ return to calling function
.end
