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

int nombre_fois(const int * __T, int __n, size_t __P) {

    int nombre_fois = 0;

    for (size_t i = 0; i < __P; i++) {

        if (__T[i] == __n) {
            nombre_fois++;
        }
    }

    return nombre_fois;
}

Stat analyse_stat(const int * __T, size_t __N) {

    double moyenne = 0;
    double ecart_type = 0;
    int sum = 0;
    double ecart_carre = 0;

    // Sum the elements of i
    for (size_t i = 0; i < __N; i++) {
        sum += __T[i];
    }

    moyenne = ((double) sum) / __N;

    for (size_t i = 0; i < __N; i++) {
        ecart_carre += (__T[i] - moyenne)*(__T[i] - moyenne);
    }

    if ( __N == 1 ) {
        ecart_type = 0;
    } else {
        ecart_type = sqrt(ecart_carre/(__N - 1));
    }

    Stat s = {moyenne, ecart_type};
    return s;
}

bool est_palindrome(const int * __T, size_t __N) {

    for (size_t i = 0; i < __N/2; i++) {
        if (__T[i] != __T[__N - i - 1]) return false;
    }

    return true;
}

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