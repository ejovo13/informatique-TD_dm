#include "TD2.h"
#include "ejovo_matrix.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>

#define FLOAT_TOLERANCE 0.0001
// #define FLOAT_TOLERANCE 0.00000000000001

int main() {

    // ex1 - indice_min
    int tab[] = {1, 2, 3, 4, 5, 6, 8, 9};
    int tab1[] = {1, 5, -3, 1, 9, -5, 5};
    int tab2[] = {5, 1, 5, 7, 2, 5, 7, 2, 7, -10};

    printf("min indice tab: %d\n", indice_min(tab, 8));
    printf("min indice tab1: %d\n", indice_min(tab1, 8));
    printf("min indice tab2: %d\n", indice_min(tab2, 10));

    assert(indice_min(tab, 8) == 0);
    assert(indice_min(tab1, 8) == 5);
    assert(indice_min(tab2, 10) == 9);

    // ex2 - nombre_fois
    int tab3[] = {1, 1, 2, 3, 4, 6, 2, 4, 7, 2, 4, 7, 27, 8, 2, 4, 2, 1, 3, 4, 6, 2, 6};

    assert(nombre_fois(tab3, 1, 23) == 3);
    assert(nombre_fois(tab3, 4, 23) == 5);
    assert(nombre_fois(tab3, 7, 23) == 2);
    assert(nombre_fois(tab3, 0, 23) == 0);
    assert(nombre_fois(tab3, 6, 23) == 3);

    // ex3 - ecart_type et moyenne
    int tab4[] = {1, 1, 1, 1, 1};
    int tab5[] = {1, 2, 3, 4, 5};

    Stat stat, stat2;
    stat = analyse_stat(tab4, 5);
    stat2 = analyse_stat(tab5, 5);

    assert(stat.ecart_type == 0);
    assert(stat.moyenne == 1);

    assert(stat2.moyenne == 3);
    assert(fabs(stat2.ecart_type - 1.581139) < FLOAT_TOLERANCE);

    // ex4 - palindrome
    int tab6[] = {1, 2, 3, 2, 1};
    int tab7[] = {1, 2, -10, -10, 2, 1};
    int tab8[] = {1, 1, 2, 2};
    int tab9[] = {1, 2, 3, 4, 5, 4, 3, 2, 0};

    assert(est_palindrome(tab6, 5));
    assert(est_palindrome(tab7, 6));

    assert(!est_palindrome(tab8, 4)); // tab8 and tab9 are not palindromes
    assert(!est_palindrome(tab9, 9));

    // ex5


    // ex6


    // ex7




    return 0;
}