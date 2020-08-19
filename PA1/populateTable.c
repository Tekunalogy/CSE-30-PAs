/* 
 * Filename: populateTable.c
 * Author: Kunal Singla
 * UserId: cs30s220eq
 * Date: 8/17/2020
 * Sources of help: C documentation, Piazza
 */

#include "pa1.h"
#include <string.h>

/*
 * Name: populateTable
 * Function Prototype: void populateTable( linkedListNode_t ** hashtbl, 
 *                                                      FILE * dataFile );
 * Description: Populates hashtable with contents of file.
 * Parameters:  double pointer to hashtable
 *              and a pointer to a FILE object
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 */
void populateTable( linkedListNode_t ** hashtbl, FILE * dataFile )
{
    char string[STRING_BUFFER];
    //fgets will return NULL when at the end of the file.
    //while loop exits at NULL
    while(fgets(string, sizeof(string), dataFile))
    {
        //Replaces newline character \n with null terminator \0
        char * newLineChar = strchr(string, NEWLINE_CHAR);
        if(newLineChar)
            *newLineChar = NULL_TERMINATOR;
            
        //for loop used to change each letter in string to lowercase
        for(int i = 0; string[i]; i++)
        {
			string[i] = tolower(string[i]);
		}

        llTableAddString(hashtbl, string);
    }
}