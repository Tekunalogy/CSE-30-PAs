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
#define EMAILS_10 "emails/emails_10"
#define EMAILS_100 "emails/emails_100"
#define EMAILS_1000 "emails/emails_1000"
#define EMAILS_10000 "emails/emails_10000"
#define EMAILS_ALL "emails/emails_all"
#define FIRST_TEN 10

/* 
 * Function Name: testEmptyFile
 * Function prototype: void testEmptyFile();
 * Description: This test is to make sure hashtable lists are NULL.
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 */
void testEmptyFile()
{
	//TEST EMPTY FILE
	linkedListNode_t ** table = newLinkedListArray(DEFAULT_SIZE);
	FILE *fptr = fopen(EMAILS_0, "r");
	populateTable(table, fptr);
	//test first 10 to check if lists are null
	for(int i = 0; i < FIRST_TEN; i++)
	{
		TEST(table[i] == NULL);
	}
	fclose(fptr);
	cleanup(table);
}

/* 
 * Function Name: testEmptyFile
 * Function prototype: void testEmptyFile();
 * Description: This test is to make sure hashtable lists are NULL.
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 */
void testFileWithEmails(const char * filePath)
{
	//TEST FILE WITH 10 EMAILS
	linkedListNode_t ** table = newLinkedListArray(DEFAULT_SIZE);
	FILE *fptr = fopen(filePath, "r");
	
	char tempString[STRING_BUFFER];
	
	fgets(tempString, sizeof(tempString), fptr);

	//Replaces newline character \n with null terminator \0
	char * newLineChar = strchr(tempString, NEWLINE_CHAR);
	if(newLineChar)
		*newLineChar = NULL_TERMINATOR;

	//for loop used to change each letter in string to lowercase
	for(int i = 0; tempString[i]; i++)
	{
		tempString[i] = tolower(tempString[i]);
	}

	//Sets the position of fgets back to the beginning of the file
	fseek(fptr, 0, SEEK_SET);
	populateTable(table, fptr);
	fclose(fptr);

	// checks table for word
	TEST(checkTable(tempString, table));

	cleanup(table);
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
	testEmptyFile();
	testFileWithEmails(EMAILS_10);
	testFileWithEmails(EMAILS_100);
	testFileWithEmails(EMAILS_1000);
	testFileWithEmails(EMAILS_10000);
	testFileWithEmails(EMAILS_ALL);
	fprintf(stderr, "\nDone running tests.\n");
	return 0;
}
