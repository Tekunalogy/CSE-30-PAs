/*
* Filename: extractParts.s
* Author: Kunal Singla
* UserId: CSE30S220EQ
* Date: 08/29/2020
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


	.text
	.type	extractParts, %function @ indication that main is a function

/*
* Function Name: extractParts
* Function prototype:
		void extractParts( unsigned long ieeeBin, ieeeParts_t * fill );
* Description: 	This function will take in a single-precision IEEE-754 floating
point number and extract its various parts to fill the passed in struct.
* Side Effects: None
* Error Conditions: None
* Return Value: Unsigned long
* Registers used:
*   <register> - <use> -- <description of what the value represents>
* example:
*   r0 - char -- stores current char of string
*   r4 - string -- stores the string pointer
*/

extractParts:
	/* PROLOGUE */
	push	{fp, lr}                @ stack frame register save
	add	fp, sp, FP_OFFSET       @ locate our frame pointer

	/* START OF MAIN PROGRAM */


	/* END OF MAIN PROGRAM */

epilogue:
	/* EPILOGUE */
	mov	r0, EXIT_SUCCESS        @ set return to EXIT_SUCCESS
	sub	sp, fp, FP_OFFSET       @ restore stack frame top
	pop	{fp, lr}                @ remove stack frame and restore
	bx	lr                      @ return to calling function
.end