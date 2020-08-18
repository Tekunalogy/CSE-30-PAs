/* 
 * Filename: retrieveLinkedList.c
 * Author: Kunal Singla
 * UserId: cs30s220eq
 * Date: 8/17/2020
 * Sources of help: C documentation, Piazza
 */

#include "pa1.h"


/*
 * Name: retrieveLinkedList
 * Function Prototype: linkedListNode_t *retrieveLinkedList(
 *                                          linkedListNode_t ** hashtbl, 
 *                                                       char * string);
 * Description: 
 * Parameters:  double pointer to hashtable
 *              and a string in the form of a char pointer
 * Side Effects: None
 * Error Conditions: None
 * Return Value: The element of hashtbl at index.
 */
linkedListNode_t *retrieveLinkedList(linkedListNode_t ** hashtbl, char *string)
{
    unsigned int index = hash(string) % DEFAULT_SIZE;
    return hashtbl[index];
}