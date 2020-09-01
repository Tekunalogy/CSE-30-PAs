/*
* Filename: parseNums.s
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
	.extern strtoul			@ function to write a char to stdout
	.global parseNum		@ defining global main function

@ Constants
	.equ 	FP_OFFSET, 4            @ fp offset in simple frame
	.equ 	EXIT_SUCCESS, 0         @ value for successful ending of program
        .equ 	ARGV_OFFSET, 8          @ value for successful ending of program
	.equ 	HEXADECIMAL, 16     	@ Base-16 factor
	.equ 	NULL_TERMINATOR, 0x0    /* Null terminator character '\0' for
                                           detecting end of string */

@ Text segment
	.text
	.type	parseNum, %function	@ indication that main is a function

/*
* Function Name: parseNum
* Function prototype: unsigned long parseNum( char * argv[] );
* Description: 	This function is used to parse a string with a hexadecimal
		number to an unsigned long
* Side Effects: None
* Error Conditions: None
* Return Value: Unsigned long
* Registers used:
*   <register> - <use> -- <description of what the value represents>
* example:
*   r0 - char -- stores current char of string
*   r4 - string -- stores the string pointer
*/

parseNum:
	/* PROLOGUE */
	push	{fp, lr}                @ stack frame register save
	add	fp, sp, FP_OFFSET       @ locate our frame pointer

	/* START OF MAIN PROGRAM */
                                        @ First argument of strtoul
        ldr     r0, [r0, ARGV_OFFSET]   /* This line is used to retrieve the
                                        string (3rd element in argv) */
                                        
                                        @ Second argument of strtoul
	mov	r1, NULL_TERMINATOR     @ Stop at null terminator in string
        
                                        @ Third argument of strtoul
	mov	r2, HEXADECIMAL         @ Set input base to 16 (hex)
	bl	strtoul                 @ Call the strtoul function
                                        /* r0 will be populated with the parsed
                                        unsigned long and returned. */
	/* END OF MAIN PROGRAM */

epilogue:
	/* EPILOGUE */
	sub	sp, fp, FP_OFFSET       @ restore stack frame top
	pop	{fp, lr}                @ remove stack frame and restore
	bx	lr                      @ return to calling function
.end
