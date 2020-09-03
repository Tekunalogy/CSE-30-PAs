/*
 * File: pa3.h
 *
 *
 * Description: Header file that contains function prototypes and constants
 *
 *
 * XXX Only add constants to this file at the bottom.
 * DO NOT EDIT FUNCTION PROTOTYPES OR PREDEFINED CONSTANTS
 *
 */

#ifndef PA3_H		/* Macro Guard */
#define PA3_H
#include <stdio.h>


#define FLAGS "s:h:"
#define HEAP_FLAG 'h'
#define STACK_FLAG 's'
#define print_String "%s"
#define MIN_ARGS 3
#define init_ch '0'
#define init_long 0


typedef struct fpbits{
	unsigned char sign;
	signed char exp;
	unsigned long mantissa;
}ieeeParts_t;


/* Assembly Function Prototypes */
unsigned long parseNum(char * argv[]);
void extractParts(unsigned long ieeeBin, ieeeParts_t * fill);

#endif
