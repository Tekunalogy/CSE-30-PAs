/* 
 * Filename: prependNode.c
 * Author: Kunal Singla
 * UserId: cs30s220eq
 * Date: 8/16/2020
 * Sources of help: C documentation, Piazza
 */

#include <string.h>
#include "pa1.h"


/*
 * Name: prependNode
 * Function Prototype: void prependNode( linkedListNode_t ** head, char * str );
 * Description: prepends a new a node to the front of linked list
 * Parameters:  linkedList head node double pointer
 *              and a string in the form of a char pointer
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 */
void prependNode( linkedListNode_t ** head, char * str )
{
    linkedListNode_t * newNode = newLinkedListNode();
    char * strCopy = strcp(str);
    newNode->value = strCopy;

    newNode->next = *head;
    *head = newNode;
}