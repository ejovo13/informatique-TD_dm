#ifndef TD2
#define TD2

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

/**@file
 * @author Evan Voyles
 * @date October 12th
 */

/**
 * Renvoie l'indice du plus petit element d'un tableau d'entiers
 *
 * Exemple:
 * ```{C}
 * int min_array[7] = {1, -3, 14, 3, -50, 20, 40};
 * int i = indice_min(min_array, 7); // i <- 4
 * ```
 * @param __T Tableau des entiers
 * @param __N Taille du tableau
 * @return Indice du plus petit element
 */
int indice_min(const int * __T, size_t __N);

/**
 * Compter le nombre de fois que `__n` apparait dans le tableau `__T`
 *
 * @param __T Tableau des entiers
 * @param __n Valeur a comparer
 * @param __P Taille du tableau `__T`
 *
 * @return Le nombre des fois ou `__n` appartient a `__T`
 *
 */
int nombre_fois(const int * __T, int __n, size_t __P);

// Creer une structure pour stocker les resultats de l'analyse statistique
/**
 * Structure qui contient de l'information statistique basique
 */
typedef struct stat {
    double moyenne;
    double ecart_type;
} Stat;

/**
 * Calculer la moyenne et ecart type d'un tableau des entiers
 *
 * @param __T Tableau des entiers
 * @param __N Taille du tableau
 * @return Une structure emballant la moyenne et ecart type de `__T`
 */
Stat analyse_stat(const int * __T, size_t __N);

/**
 * Determiner si un tableau des entiers est un palindrome
 *
 * Par example, `{1, 2, 3, 2, 1}` est un palindrome mais `{1, 1, 2, 2}` ne l'est pas
 * @param __T Tableau des entiers
 * @param __N Taille du tableau
 * @return Vrai si `__T` est un palindrome, sinon Faux
 */
bool est_palindrome(const int * __T, size_t __N);

/**
 * Modifie un tableau des entiers en remplacant les doublons par 0
 *
 * @param __T Tableau a modifier
 * @param __N Taille du tableau
 *
 * @attention `remplacement_doublon` modifie le tableau `__T` qui est donne comme argument
 *
 * ```C
 * int arr[10] = {1, 4, -3, 13, 4, 6, 1, 13, 1, 5}
 * remplacement_doublon(arr, 10); // arr := {1, 4, -3, 13, 0, 6, 0, 0, 0, 5}
 * ```
 */
void remplacement_doublon(int * __T, size_t __N);

/**
 * Stocker les nombres premiers inferieurs ou egaux a `__N` dans un tableau en utilisant
 * la methode du crible d'erastosthene
 *
 * @param __N La valeur maximum
 * @returns Un tableau des entiers de taille `__N - 1` alloue par malloc
 */
int * crible_erastosthene(size_t __N);



#endif