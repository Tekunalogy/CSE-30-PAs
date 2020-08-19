/*
 * Filename: testprependNode.c
 * uthor: Kunal Singla
 * UserId: cs30s220eq
 * Description: Unit test program to test the function hash().
 * Date: 8/17/2020
 * Sources of help: C documentation, Piazza
 */

#include <string.h>
#include <stdlib.h>

#include "test.h" /* For TEST() macro and stdio.h */
#include "pa1.h"

/* 
 * Function Name: testprependNode
 * Function prototype: void testprependNode();
 * Description: The test method. Tests designed here.
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 */
void testprependNode()
{
	//TEST REGULAR STRING
	linkedListNode_t ** table = newLinkedListArray(DEFAULT_SIZE);
	prependNode(&table[0], "STRING");
	TEST(strcmp(table[0]->value, "STRING") == 0);
	TEST(table[0]->next == NULL);

	//TEST EMPTY STRING
	prependNode(&table[1], "");
	TEST(strcmp(table[1]->value, "") == 0);
	TEST(table[1]->next == NULL);
}

/* 
 * Function Name: main()
 * Function prototype: int main();
 * Description: The test driver. Runs specified tests.
 * Side Effects: None
 * Error Conditions: None
 * Return Value: 0 on exit success.
 */
int main()
{
	fprintf(stderr, "Testing hash...\n\n");
	testprependNode();
	fprintf(stderr, "\nDone running tests.\n");
	return 0;
}
