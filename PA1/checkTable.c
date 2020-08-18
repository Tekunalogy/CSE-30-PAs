/* 
 * Filename: checkTable.c
 * Author: Kunal Singla
 * UserId: cs30s220eq
 * Date: 8/17/2020
 * Sources of help: C documentation, Piazza
 */

#include "pa1.h"

/*
 * Name: retrieveLinkedList
 * Function Prototype: int checkTable(char * str, linkedListNode_t ** hashtbl);
 * Description: This function reports if the string is seen in the hash table.
 * Parameters:  double pointer to hashtable
 *              and a string in the form of a char pointer
 * Side Effects: None
 * Error Conditions: None
 * Return Value: 0 if no linked list exists at the value hashed into using str 
 * or the linked list does exist and str is not in the linked list. 
 * 1 if the string is in the linked list at the value hashed into using str.
 */
int checkTable( char * str, linkedListNode_t ** hashtbl )
{
    //hashtable does not exist, therefore not spam. Return 0
    if(hashtbl == NULL)
        return 0;

    //retrieve linkedList in hashtable
    linkedListNode_t * linkedList = retrieveLinkedList(hashtbl, str);

    //means string does not exist in hashtable, therefore not spam. Return 0
    if(linkedList == NULL)
        return 0;

    //searches linkedList for string.
    while(linkedList != NULL)
    {
        //if found return 1
        if(strcmp(linkedList->value, str) == 0)
        {
            return 1;
        }
        linkedList = linkedList->next;
        
    }
    //if not found return 0
    return 0;
}