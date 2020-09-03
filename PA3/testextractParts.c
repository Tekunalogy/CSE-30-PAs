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

#define testingString "\n\nTesting 0x%lx:\n"

#define zero_hex 0x0
#define one_hex 0x1
#define F_hex 0xFFFFFFFF
#define hex_1 0x41260000
#define hex_2 0x40000000
#define hex_3 0xbf800000
#define hex_4 0xc47a0000

#define exp_1 -127
#define exp_2 9
#define exp_3 3
#define exp_4 -128

#define mantissa_1 0x800000
#define mantissa_2 0x800001
#define mantissa_3 0xa60000
#define mantissa_4 0xfa0000
#define mantissa_5 0xFFFFFF



/* 
 * Function Name: testExtractParts
 * Function prototype: void testExtractParts();
 * Description: This function takes in a correct struct (based on data
 *              collected from ~/../public/pa3testfpdec) and tests equivalency
 *              to struct based on extractParts() method.
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 */
void testExtractParts(unsigned long num, ieeeParts_t * correctStruct, 
                                         ieeeParts_t * myStruct)
{
    fprintf(stderr, testingString, num);
    extractParts(num, myStruct);
    TEST(correctStruct->sign == myStruct->sign);
    TEST(correctStruct->exp == myStruct->exp);
    TEST(correctStruct->mantissa == myStruct->mantissa);   
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
    fprintf(stderr, "Testing extractParts...\n");
    ieeeParts_t * correctStruct;
    ieeeParts_t * myFuncStruct;

    
    //testing 0x0
    correctStruct = &(ieeeParts_t){ 0, exp_1, mantissa_1 };
    myFuncStruct = &(ieeeParts_t){ init_ch, init_ch, init_long };
    testExtractParts(zero_hex, correctStruct, myFuncStruct);

    //testing 0x1
    correctStruct = &(ieeeParts_t){ 0, exp_1, mantissa_2 };
    myFuncStruct = &(ieeeParts_t){ init_ch, init_ch, init_long };
    testExtractParts(one_hex, correctStruct, myFuncStruct);

    //testing 0xFFFFFFFF
    correctStruct = &(ieeeParts_t){ 1, exp_4, mantissa_5 };
    myFuncStruct = &(ieeeParts_t){ init_ch, init_ch, init_long };
    testExtractParts(F_hex, correctStruct, myFuncStruct);

    //testing 0x41260000
    correctStruct = &(ieeeParts_t){ 0, exp_3, mantissa_3 };
    myFuncStruct = &(ieeeParts_t){ init_ch, init_ch, init_long };
    testExtractParts(hex_1, correctStruct, myFuncStruct);

    //testing 0x40000000
    correctStruct = &(ieeeParts_t){ 0, 1, mantissa_1 };
    myFuncStruct = &(ieeeParts_t){ init_ch, init_ch, init_long };
    testExtractParts(hex_2, correctStruct, myFuncStruct);

    //testing 0xbf800000
    correctStruct = &(ieeeParts_t){ 1, 0, mantissa_1 };
    myFuncStruct = &(ieeeParts_t){ init_ch, init_ch, init_long };
    testExtractParts(hex_3, correctStruct, myFuncStruct);

    //testing 0xc47a0000
    correctStruct = &(ieeeParts_t){ 1, exp_2, mantissa_4 };
    myFuncStruct = &(ieeeParts_t){ init_ch, init_ch, init_long };
    testExtractParts(hex_4, correctStruct, myFuncStruct);


    fprintf(stderr, "\nDone running tests.\n");
	
    return EXIT_SUCCESS;
}
