#include <stdio.h>
#include "TD2.h"
#include "TD6.h"

int main() {

    printf("Hello world\n");

    int min_array[] = {1, -3, 14, 3, -50, 20, 40};

    printf("Indice de minimum: %d\n", indice_min(min_array, 7));

    int nombre_fois_array[] = {1, 2, 3, 2, 2, 4, 1, 5, 23, -123, 10, 2, 22103, 3};

    printf("Nombres de fois de 2: %d\n", nombre_fois(nombre_fois_array, 2, 14));

    int stat_array[] = {1, 3, 5, 4, 5, 3, 9, 3};

    Stat res = analyse_stat(stat_array, 8);

    printf("Moyenne: %lf, ecart_type: %lf\n", res.moyenne, res.ecart_type);

    int pal_test[] = {1, 2, 3, 5, 3, 2, 1};

    printf("Is palindrome?: %d\n", est_palindrome(pal_test, 7));

    int * primes = crible_erastosthene(1000);

    for (int i = 0; i < 999; i++) {
        if(primes[i] != -1) printf("%5d", primes[i]);
    }

    printf("Trying to calculate the value of pi: %lf\n", 4*leibniz_pi(0.0001));

    char str[] = "Hello this is a string k k ";

    decompose_string(str);





    return 0;
}