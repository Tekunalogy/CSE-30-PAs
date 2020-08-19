/*
 * Filename: testpopulateTable.c
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
#define EMAILS_0 "emails/no_emails"
#define EMAILS_10 "emails/email_10"
#define EMAILS_100 "emails/email_100"
#define EMAILS_1000 "emails/email_1000"
#define EMAILS_10000 "emails/email_10000"
#define EMAILS_ALL "emails/email_all"

/* 
 * Function Name: testpopulateTable
 * Function prototype: void testpopulateTable();
 * Description: The test method. Tests designed here.
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 */
void testpopulateTable()
{
	//TEST EMPTY FILE
	linkedListNode_t ** table = newLinkedListArray(DEFAULT_SIZE);
	FILE *fptr = fopen(EMAILS_0, "r");
	populateTable(table, fptr);
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
	testpopulateTable();
	fprintf(stderr, "\nDone running tests.\n");
	return 0;
}
