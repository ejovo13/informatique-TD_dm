// Leibniz method to calculate pi
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


/**@file
 * @brief Public API for the functions defined when solving TD6
 * @author Evan Voyles
 * @date October 25th
 */
#define MAX_ITERATIONS 1000000

/**
 * Return the number of words in a string
 *
 * A word is defined as a non-zero sequence of characters that are not spaces, newlines, or null characters.
 * This function is called by the `decompose_string` function
 *
 */
size_t count_words(const char *__string);

/**
 * Return an approximation of PI within a certain precision
 *
 */
double leibniz_pi(double __precision);

/**
 * Decompose a string at its word boundaries
 *
 *
 * @returns An array of pointers the words of __string, where the last pointer is null.
 *
 * For example, if I decompose a string of 4 words, decompose_string will return a pointer array that
 * has 5 elements.
 *
 */
char ** decompose_string(const char * __string);