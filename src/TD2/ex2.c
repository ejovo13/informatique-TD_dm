#include "TD2.h"

int nombre_fois(const int * __T, int __n, size_t __P) {

    int nombre_fois = 0;

    for (size_t i = 0; i < __P; i++) {

        if (__T[i] == __n) {
            nombre_fois++;
        }
    }

    return nombre_fois;
}