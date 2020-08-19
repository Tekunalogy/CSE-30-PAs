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
#include <stdlib.h>

/*
 * Name: main
 * Function Prototype: int main( int argc, char * argv[] )
 * Description: This is the main spam filter program to filter out spam email
 *              addresses.
 * Parameters:  number of arguments
 *              array of string arguments
 * Return Value: 0 if program exits successfully. 1 if there is an error.
 */
int main(int argc, char *argv[])
{
    //initialize option variable for getopt
    int option;
    //initialize FILE pointer
    FILE *fptr;
    //initialize empty hashtable
    linkedListNode_t **hashtable = newLinkedListArray(DEFAULT_SIZE);
    opterr = 0;
    optind = 0;
    while ((option = getopt(argc, argv, FLAGS)) != -1)
    {
        switch (option)
        {
            case 'h':
                printf("%s", LONG_USAGE);
                return EXIT_SUCCESS;
                break;

            case 'i':
                if ((fptr = fopen(optarg, "r")) == NULL)
                {
                    perror(FILTER_ERR);
                    fprintf(stderr, "%s", SHORT_USAGE);
                    return EXIT_FAILURE;
                }
                break;

            default:
                fprintf(stderr, "%s", LONG_USAGE);
                return EXIT_FAILURE;
                break;
        }
        
    }
    
    if(optind <= 1 || argc > 3)
    {
        fprintf(stderr, "%s", INVALID_ARGS);
        fprintf(stderr, "%s", SHORT_USAGE);
        return EXIT_FAILURE;
    }

    //read from file and then close file.
    populateTable(hashtable, fptr);
    fclose(fptr);

    launchUserQuery(hashtable);

    //cleanup function for hashtable
    cleanup(hashtable);
    return EXIT_SUCCESS;
}