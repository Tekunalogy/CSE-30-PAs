/* 
 * Filename: hash.c
 * Author: Kunal Singla
 * UserId: cs30s220eq
 * Date: 8/16/2020
 * Sources of help: C documentation, Piazza
 */

#include <string.h>
#include "pa1.h"

/*
 * Name: hash
 * Function Prototype: unsigned int hash( char * str );
 * Description: Used to create the hash key of a string
 *              and returns an unsigned integer
 * Parameters: a string in the form of a char pointer
 * Side Effects: Overflow (allowed)
 * Error Conditions: None
 * Return Value: A pointer to a char (beginning of string)
 */
unsigned int hash(char *str)
{
	unsigned int hashVal = HASH_START_VAL;
	int length = strlen(str);
	int i;
	for(i = 0; i < length; i += 2)
	{
		char ch = (*(str + i));
		hashVal *= HASH_PRIME;
		hashVal += ch;
	}
	for(i = 1; i < length; i += 2)
	{
		char ch = (*(str + i));
		hashVal *= HASH_PRIME;
		hashVal += ch;
	}
	return hashVal;
}