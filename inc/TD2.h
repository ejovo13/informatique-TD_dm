#ifndef TD2
#define TD2

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
// Renvoi l'indice du plus petit element d'un tableau d'entiers
int indice_min(const int * __T, size_t __N);

// Compter le nombre de fois que '__n' apparait dans le tableau '__T'
int nombre_fois(const int * __T, int __n, size_t __P);

// Creer une structure pour stocker les resultats de l'analyse statistique
typedef struct stat {
    double moyenne;
    double ecart_type;
} Stat;

Stat analyse_stat(const int * __T, size_t __N);

bool est_palindrome(const int * __T, size_t __N);

void remplacement_doublon(int * __T, size_t __N);

int * crible_erastosthene(size_t __N);



#endif