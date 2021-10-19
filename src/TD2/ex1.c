#include "TD2.h"

int indice_min(const int * __T, size_t __N) {

    int indice_min = -1;
    int min = __T[0];

    for (size_t i = 1; i < __N; i++) {

        if (__T[i] < min) {

            min = __T[i];
            indice_min = i;
        }
    }

    return indice_min;
}