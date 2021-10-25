#ifndef TD5
#define TD5

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>


/**@file
 * @brief Public API for the functions defined when solving TD5
 * @author Evan Voyles
 * @date October 25th
 */

/**
 * Initialize a 1-dimensional flat array used to model a 2-d array of nb_lignes x nb_cols
 *
 * @returns A 1-d float array of size nb_lignes * nb_cols
 */
float *init_tab(size_t __nb_lignes, size_t __nb_cols);

/**
 * Get the element "tab[irow][icol]" for a flattened 2d array
 *
 * @return returns the element at tab[nb_cols * irow + icol]
 */
float get_in_tab(const float *__tab, size_t __irow, size_t __icol, size_t __nb_lignes, size_t __nb_cols);

/**
 * Set the element "tab[irow][icol]" for a flattened 2d array
 *
 */
void set_in_tab(float *__tab, size_t __irow, size_t __icol, size_t __nb_lignes, size_t __nb_cols, float __value);

/**
 * Returns a size 4 float array that contains the elements adjacent to tab[irow][icol]
 *
 * @returns [N, E, S, W], where N, E, S, W are the elements to the North, East, South, and West of tab[irow][icol]
 *
 */
float *adjacency(const float *__tab, size_t __i, size_t __j, size_t __nb_lignes, size_t __nb_cols);

#endif