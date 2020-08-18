/* 
 * Filename: llTableAddString.c
 * Author: Kunal Singla
 * UserId: cs30s220eq
 * Date: 8/17/2020
 * Sources of help: C documentation, Piazza
 */

#include "pa1.h"


/*
 * Name: llTableAddString
 * Function Prototype: void llTableAddString( linkedListNode_t ** hashtbl, 
 *                                                          char *string );
 * Description: Adds a string node to the hashtable at hashed index.
 * Parameters:  hashtable double pointer
 *              and a string in the form of a char pointer
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 */
void llTableAddString( linkedListNode_t ** hashtbl, char *string )
{
    unsigned int index = hash(string) % DEFAULT_SIZE;
    prependNode(&hashtbl[index], string);
}