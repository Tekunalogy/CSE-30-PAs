/*
 * Filename: testhash.c
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
 * Function Name: testhash
 * Function prototype: void testhash();
 * Description: The test method. Tests designed here.
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 */
void testhash()
{
	TEST(hash("abc") 	== 693737);
	TEST(hash("paul") 	== 26452777);
	TEST(hash("") 		== 11);
	TEST(hash(" ") 		== 439);
	TEST(hash("\n") 	== 417);
	TEST(hash("%s") 	== 16543);
	TEST(hash("brown") 	== 952228715);
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
	testhash();
	fprintf(stderr, "\nDone running tests.\n");
	return 0;
}
