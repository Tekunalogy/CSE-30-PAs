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
    char * a;

    //initialize global var opterr to stop automatic getopt errors
    opterr = 0;
    while((option = getopt(argc, argv, FLAGS)) != -1)
    {
        switch (option)
        {
            case HEAP_FLAG:
                printf("USED -h + arg is %s\n", optarg);

                break;

            case STACK_FLAG:
                printf("USED -s + arg is %s\n", optarg);
                break;

            default:
                printf("USED none + arg is %s\n", optarg);
                break;
        }
        a = optarg;
    }
    unsigned long temp = parseNum(argv);
    printf("%lu\n", temp);

    return EXIT_SUCCESS;
}