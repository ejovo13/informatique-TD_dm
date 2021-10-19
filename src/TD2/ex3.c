#include "TD2.h"

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