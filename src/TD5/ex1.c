#include "TD5.h"

float *init_tab(size_t __nb_lignes, size_t __nb_cols) {

    float *arr = (float *) malloc(sizeof(float) * (__nb_lignes *__nb_cols));

    if (arr) { // if arr is not NULL,

        for (size_t i = 0; i < __nb_lignes *__nb_cols; i++) {
            arr[i] = 0;
        }
    }

    return arr;
}

float get_in_tab(const float *__tab, size_t __irow, size_t __icol, size_t __nb_lignes, size_t __nb_cols) {
    return __tab[__irow *__nb_lignes + __icol *__nb_cols];
}

void set_in_tab(float *__tab, size_t __irow, size_t __icol, size_t __nb_lignes, size_t __nb_cols, float __value) {
    __tab[__irow *__nb_lignes + __icol *__nb_cols] = __value;
}

float *adjacency(const float *__tab, size_t __i, size_t __j, size_t __nb_lignes, size_t __nb_cols) {

    // return the elements IMMEDIATELY next to a matrix
    float *adj = malloc(sizeof(float) * (sizeof(float) * 4));


    size_t num_elements = 4;
    size_t count = 0;
    for (int i = -1; i < 2; i += 2) {
        for (int j = -1; j < 2; j += 2) {
            // check bounds
            if (__i + i < __nb_lignes && __j + j < __nb_cols) {
                adj[count] = get_in_tab(__tab, __i + i, __j + j, __nb_lignes, __nb_cols);
            } else {
                adj[count] = 0;
            }
        }

        count++;
    }

}





