#include "TD2.h"

void remplacement_doublon(int * __T, size_t __N) {

    int old_value = __T[0];

    for (size_t i = 1; i < __N; i++) {

        if (__T[i] == old_value) { // Then we have a duplicate
            __T[i] = 0;
        } else {
            old_value = __T[i];
        }
    }
}