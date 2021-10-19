#include "TD2.h"

int * crible_erastosthene(size_t __N) {

    int * primes = (int *) malloc(sizeof(int) * (__N - 1));

    // Initialize value
    for (size_t i = 0; i <= __N - 2; i++) {
        primes[i] = i + 2;
    }

    for (size_t i = 2; i < (size_t) sqrt(__N); i++) {

        for (size_t j = 0; j < __N - 1; j++) {

            if ( primes[j] % i == 0 && primes[j] != i ) {
                primes[j] = -1;
            }
        }
    }

    return primes;
}