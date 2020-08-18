/* 
 * Filename: populateTable.c
 * Author: Kunal Singla
 * UserId: cs30s220eq
 * Date: 8/17/2020
 * Sources of help: C documentation, Piazza
 */

#include "pa1.h"


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
    char string[256];
    while(!feof(dataFile))
    {
        fgets(string, sizeof(string), dataFile);
        for(int i = 0; string[i]; i++){
			if(string[i] == '\n')
				string[i] = '\0';
			string[i] = tolower(string[i]);
		}
        llTableAddString(hashtbl, string);
    }
}