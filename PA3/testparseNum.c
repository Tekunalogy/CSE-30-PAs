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

#define testingString_1 "\n\nTesting Length %d Hex Strings %d times:\n"
#define testingString_2 "\n\nTesting Custom Hex String: %s\n"

#define hexChs {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}
#define base_16 16
#define index_2 2
#define three_args 3
#define num_tests 5

#define length_8_hex 8
#define length_6_hex 6
#define length_4_hex 4
#define length_1_hex 1

#define zero_hex "0x0"
#define one_hex "0x1"
#define F_hex "0xFFFFFFFF"
#define hex_1 "0x41260000"


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
    //create a new string with length + null terminator at the end
    char * str = malloc(length + 1);

    //initialize all possible hex characters
    char hex_chars[] = hexChs;

    //build a hex string choosing randomly selected characters from array
    for (int i = 0; i < length; i++)
    {
        str[i] = hex_chars[rand() % 16];
    }
    
    //add null terminator at the end of the string
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
void testNHexadecimalStrings(unsigned int n, int length)
{
    fprintf(stderr, testingString_1, length, n);
    char * testString;
    //used to "simulate" argv like in a regular main function
    char * argv[three_args];

    for(int i = 0; i < n; ++i)
    {
        testString = generateRandomHexString(length);
        argv[index_2] = testString;
        unsigned long myfuncOutput = parseNum(argv);
        unsigned long strtoulOutput = strtoul(testString, '\0', base_16);
        TEST(myfuncOutput == strtoulOutput);

        //since malloc was used, we free this pointer
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
    fprintf(stderr, testingString_2, input);
    char * argv[three_args];
    argv[index_2] = input;
    unsigned long myfuncOutput = parseNum(argv);
    unsigned long strtoulOutput = strtoul(input, '\0', base_16);
    TEST(myfuncOutput == strtoulOutput);
}



/* 
 * Function Name: main()
 * Function prototype: int main();
 * Description: The test driver. Runs specified tests.
 * Side Effects: Prints to stderr
 * Error Conditions: None
 * Return Value: 0 on exit success.
 */
int main()
{
	fprintf(stderr, "Testing parseNum...\n\n");
	
    //testing x length hex strings, n number of times
    testNHexadecimalStrings(num_tests, length_8_hex);
    testNHexadecimalStrings(num_tests, length_6_hex);
    testNHexadecimalStrings(num_tests, length_4_hex);
    testNHexadecimalStrings(num_tests, length_1_hex);

    //testing custom edge cases, not easily automated
    testSpecificHexadecimalStrings(zero_hex);
    testSpecificHexadecimalStrings(one_hex);
    testSpecificHexadecimalStrings(F_hex);
    testSpecificHexadecimalStrings(hex_1);

	fprintf(stderr, "\nDone running tests.\n");

	return EXIT_SUCCESS;
}
