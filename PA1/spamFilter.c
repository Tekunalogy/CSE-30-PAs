/* 
 * Filename: spamFilter.c
 * Author: Kunal Singla
 * UserId: cs30s220eq
 * Date: 8/17/2020
 * Sources of help: C documentation, Piazza, Textbook (Harris)
 */

#include "pa1.h"
#include "pa1Strings.h"
#include <getopt.h>

/*
 * Name: main
 * Function Prototype: int main( int argc, char * argv[] )
 * Description: This is the main spam filter program to filter out spam email
 *              addresses.
 * Parameters:  number of arguments
 *              array of string arguments
 * Return Value: 0 if program exits successfully. 1 if there is an error.
 */
int main(int argc, char * argv[])
{
    int option;
    FILE *fptr;
    linkedListNode_t ** hashtable;
    while((option = getopt(argc, argv, FLAGS)) != -1)
    {
        switch(option)
        {
            case 'h':
                printf("%s", LONG_USAGE);
                return 0;
                break;

            case 'i':
                printf("%s\n", optarg);
                if((fptr = fopen(optarg, "r")) == NULL)
                {
                    printf("%s", FILTER_ERR);
                    return 1;
                }
                
                break;
            case ':':
                printf("JELLO\n");
                break;

            default:
                if(optind >= argc)
                {
                    fprintf(stderr, "%s", INVALID_ARGS);
                }
                break;
        }
   }

//    cleanup(hashtable);
   return 0;
}