/*
 File:				lab2_in-lab_exercises.c
 Purpose:			Implementation of functions for lab 2 in-lab exercises
 Author:			Your names
 Student #s:	12345678 and 12345678
 CWLs:	      cwl1 and cwl2
 Date:				Add the date here
 */

#include "lab2_in-lab_exercises.h"
#include <stdlib.h>
#include <string.h>

/*
 * Let's start with something easy.  There are 3 unit tests
 * for this function.
 *
 * Swaps the contents of two integer variables using pointers
 *
 * PARAM:     first_int is a pointer to an int
 * PARAM:     second_int is a pointer to an int
 * PRE:       both pointers are valid pointers to int
 * POST:      the contents of two integer variables are swapped
 * RETURN:    VOID
 */
void swap_ints(int* first_int, int* second_int)
{
	int temp;

	temp = *first_int;
	*first_int = *second_int;

	*second_int = temp;
  // Insert your code here
}

/*
 * Now let's try something a little more challenging.
 *
 * Reverses the contents of the string passed to the
 * function.  Does not move the terminating null '\0'
 * character.
 *
 * PARAM:     string is a pointer to an array of char (a string)
 * PRE:       the array of char terminates with a null '\0'
 * POST:      the char array has been reversed
 * RETURN:    VOID
 */
void reverse_string(char* string)
{
  // Insert your code here
	char temp;
	int size_l = 0;
	int i = 0;

	if (string != NULL) {
		size_l = strlen(string);
	}
	
	for (i = 0;i < (size_l / 2); i++) {
		temp = *(string + i);
		*(string + i) = *(string + size_l - 1 - i);
		*(string + size_l - 1 - i) = temp;
	}
	
}

/*
 * Let's see how well you read the lab document.
 *
 * Determines if candidate contains sample, and returns
 * 1 if  it does, and 0 if it does not.
 *
 * PARAM:     candidate is a pointer to an array of char (a string)
 * PARAM:     sample is a pointer to an array of char (a string)
 * PRE:       the arrays of char terminate with a null '\0'
 * PRE:       candidate != NULL; sample != NULL
 * POST:      N/A
 * RETURN:    IF candidate contains sample THEN 1
 *            ELSE 0.
 */
int contains_sample(char* candidate, char* sample)
{
  // Replace this return statement with your code
	int size_c = 0;
	int size_s = 0;
	int cmp = 0;

	if ((candidate != NULL)&&(sample != NULL)) {
		size_c = strlen(candidate);
		size_s = strlen(sample);

		cmp = strstr(candidate, sample);
			if (cmp != NULL) {
				return 1;
		}
			else {
				return 0;
			}
	}

	return 0;
}

/*
 * Returns the first index where sample is located inside the
 * candidate.  For example:
 * IF candidate = "Hello", sample = "Hello", RETURNS 0
 * IF candidate = "soupspoon", sample = "spoon", RETURNS 4
 * IF candidate = "ACGTACGTA", sample = "CGT", RETURNS 1
 * IF candidate = "CGTACGTA", sample = "CGTT", returns -1
 *
 * PARAM:     candidate is a pointer to an array of char (a string)
 * PARAM:     sample is a pointer to an array of char (a string)
 * PRE:       the arrays of char terminate with a null '\0'
 * POST:      N/A
 * RETURN:    IF candidate contains sample
 *            THEN the index where the first letter of sample is inside candidate
 *            ELSE -1.
 */
int find_index(char* candidate, char* sample)
{
  // Replace this return statement with your code
	char* ind;

	if ((candidate == NULL)||(sample == NULL)) {
		return -1;
	}

	ind = strstr(candidate, sample);

	if (ind != NULL) {
		return (ind-candidate);
	}

	return -1;

}
