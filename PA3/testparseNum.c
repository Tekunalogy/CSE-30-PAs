/*
 * Filename: testextractParts.c
 * uthor: Kunal Singla
 * UserId: cs30s220eq
 * Description: Unit test program to test the function extractParts().
 * Date: 09/02/2020
 * Sources of help: C documentation, Piazza
 */

#include <string.h>
#include <stdlib.h>

#include "test.h" /* For TEST() macro and stdio.h */
#include "pa3.h"
#define hexChs {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}
#define base_16 16
#define three_args 3

/* 
 * Function Name: generateRandomHexString
 * Function prototype: char * generateRandomHexString();
 * Description: This is a helper function to generate a random n-length hex
 *              string.
 * Side Effects: None
 * Error Conditions: None
 * Return Value: A hex string
 */
char * generateRandomHexString(unsigned int length)
{
    char * str = malloc(length + 1);
    char hex_chars[] = hexChs;

    for (int i = 0; i < length; i++)
    {
        str[i] = hex_chars[rand() % 16];
    }
    
    str[length]='\0';
    return str;
}

/* 
 * Function Name: testNHexadecimalStrings
 * Function prototype: void testNHexadecimalStrings();
 * Description: This test is to randomly generate n number hex strings and
 *              compare output between parseNum and strtoul.
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 */
void testNHexadecimalStrings(unsigned int n)
{
    char * testString;
    char * argv[three_args];

    for(int i = 0; i < n; ++i)
    {
        testString = generateRandomHexString(8);
        argv[2] = testString;
        unsigned long myfuncOutput = parseNum(argv);
        unsigned long strtoulOutput = strtoul(testString, '\0', base_16);
        TEST(myfuncOutput == strtoulOutput);
        free(testString);
    }
}

/* 
 * Function Name: testSpecificHexadecimalStrings
 * Function prototype: void testSpecificHexadecimalStrings();
 * Description: This test is to test a specific hex string input
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 */
void testSpecificHexadecimalStrings(char * input)
{
    char * argv[three_args];
    argv[2] = input;
    unsigned long myfuncOutput = parseNum(argv);
    unsigned long strtoulOutput = strtoul(input, '\0', base_16);
    TEST(myfuncOutput == strtoulOutput);
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
	fprintf(stderr, "Testing parseNum...\n\n");
	
    testNHexadecimalStrings(5);
    testSpecificHexadecimalStrings("0x0");
    testSpecificHexadecimalStrings("0x1");
    testSpecificHexadecimalStrings("0xFFFFFFFF");

	fprintf(stderr, "\nDone running tests.\n");

	return EXIT_SUCCESS;
}
