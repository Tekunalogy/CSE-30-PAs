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
	.global extractParts            @ defining global main function

@ Constants
	.equ 	FP_OFFSET, 4            @ fp offset in simple frame
        .equ 	ASCII_OFFSET, 48        @ ascii offset, numbers start at 48
        .equ 	SIGN_SHIFT, 31          @ bitwise shift factor for sign
        .equ 	MANT_SHIFT, 9           @ bitwise shift factor for sign
        .equ 	EXP_OFFSET, 1           @ offset for exp struct member location
        .equ 	MANT_OFFSET, 4          /* offset for mantissa struct member 
                                        location */
        .equ    MANTISSA_MASK, 0xFFFFFF @ Mask to extract mantissa
        .equ    LEADING_BIT, 0x800000   @ Factor to set leading bit to 1
        .equ    EXP_SHIFT, 23           @ Shift factor to remove mantissa
        .equ    EXP_MASK, 0xFF          @ Mask to remove sign bit after shifting
        .equ    EXP_SUB_FACTOR, 0x7F    @ subtract out IEEE bias factor (32-bit)
	.equ 	EXIT_SUCCESS, 0         @ value for successful ending of program
@ Text segment
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
        mov     r4, r0                  @ copy argument to preserved register
        mov     r5, r1                  @ copy argument to preserved register
        
        /* Finding the sign */
        lsr     r0, r0, SIGN_SHIFT      @ logical shift of 31 bits to the right
        add     r0, r0, ASCII_OFFSET    @ offset ascii value so it stores number
        strb    r0, [r5]                @ store the sign bit in the struct

        /* Finding the exponent */
        mov     r0, r4                  @ copy number from preserved register
        lsr     r0, r0, EXP_SHIFT       @ shift to remove mantissa
        and     r0, r0, EXP_MASK        @ mask to remove sign bit
        sub     r0, r0, EXP_SUB_FACTOR  @ subtract out IEEE 32-bit bias factor
        str     r0, [r5, EXP_OFFSET]    @ store the exponent in the struct

        /* Finding the mantissa */
        mov     r0, r4                  @ copy number from preserved register
        and     r0, r0, MANTISSA_MASK   @ remove everything but the mantissa
        orr     r0, r0, LEADING_BIT     @ add the hidden leading bit 1
        str     r0, [r5, MANT_OFFSET]   @ store the mantissa in the struct

	/* END OF MAIN PROGRAM */

epilogue:
	/* EPILOGUE */
	mov	r0, EXIT_SUCCESS        @ set return to EXIT_SUCCESS
	sub	sp, fp, FP_OFFSET       @ restore stack frame top
	pop	{fp, lr}                @ remove stack frame and restore
	bx	lr                      @ return to calling function
.end
