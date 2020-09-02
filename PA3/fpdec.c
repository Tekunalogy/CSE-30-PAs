/* 
 * Filename: fpdec.c
 * Author: Kunal Singla
 * UserId: cs30s220eq
 * Date: 8/29/2020
 * Sources of help: C documentation, Piazza
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "pa3.h"
#include "pa3Strings.h"

/*
 * Name: main
 * Function Prototype: int main( int argc, char * argv[] );
 * Description: Main function to extract the parts of an IEEE-754 hexadecimal
 *              input.
 * Parameters:  number of arguments
 *              array of string arguments (-s or -h and a hexadecimal number)
 * Side Effects: None
 * Error Conditions: None
 * Return Value: 0 if program exits successfully. 1 if there is an error.
 */
int main(int argc, char * argv[])
{
    //initialize option variable for getopt
    int option;
    char onHeap = 0;
    ieeeParts_t * IEEE_Parts;

    //initialize global var opterr to stop automatic getopt errors
    opterr = 0;
    if(argc < 3 || argc > 3)
        fprintf(stderr, "%s", INVALID_ARGS);
    while((option = getopt(argc, argv, FLAGS)) != -1)
    {
        switch (option)
        {
            case HEAP_FLAG:
                IEEE_Parts = malloc(sizeof(ieeeParts_t));
                onHeap = 1;
                break;

            case STACK_FLAG:
                IEEE_Parts = &(ieeeParts_t){ '0', '0', 0 };
                break;

            default:
                fprintf(stderr, "%s", SHORT_USAGE);
                return EXIT_FAILURE;
                break;
        }
    }
    
    extractParts(parseNum(argv), IEEE_Parts);

    printf(SIGN_STR, IEEE_Parts->sign);
    printf(EXP_STR, IEEE_Parts->exp);
    printf(MANTISSA_STR, IEEE_Parts->mantissa);

    if(onHeap)
        free(IEEE_Parts);
    return EXIT_SUCCESS;
}
