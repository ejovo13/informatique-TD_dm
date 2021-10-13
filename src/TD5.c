#include "TD5.h"

float * init_tab(size_t __nb_lignes, size_t __nb_cols) {

    float * arr = (float *) malloc(sizeof(float) * (__nb_lignes * __nb_cols));

    if (arr) { // if arr is not NULL,

        for (size_t i = 0; i < __nb_lignes * __nb_cols; i++) {
            arr[i] = 0;
        }
    }

    return arr;
}

float get_in_tab(const float * __tab, size_t __irow, size_t __icol, size_t __nb_lignes, size_t __nb_cols) {
    return __tab[__irow * __nb_lignes + __icol * __nb_cols];
}

void set_in_tab(float * __tab, size_t __irow, size_t __icol, size_t __nb_lignes, size_t __nb_cols, float __value) {
    __tab[__irow * __nb_lignes + __icol * __nb_cols] = __value;
}

