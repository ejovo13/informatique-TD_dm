#include "ejovo_matrix.h"

// Pour cet exercise, j'inclus le code que j'ai ecrit pour developper une
// schema matricielle pour resoudre une exercice de TP. Dans cette schema j'ai
// ecrit bcp bcp de fonctions dont vous pouver regarder les documentations sur
// le github ou construire-les localement avec doxygen.

// Bref, tout est declare en ejovo_matrix.h (vous pouvez verifier que le nom de mon compte de github
// est que j'ai touts les commits du developpement de cette "framework" matricielle) dans /inc, et
// toute fonction est defini dans `ejovo_matrix.c` dans /src

// La fonction specifique pour multiplier deux matrices c'est `Matrix_mult`

int main() {

    ejovo_seed(); // Initialize my custom random generator

    Matrix *A = Matrix_random(3, 2, 0, 5); // initialize 3 x 2 array with random integers between 0 and 5
    Matrix *B = Matrix_random(2, 5, 0, 5); // initialize 2 x 5 array

    printf("A |\n===\n");
    Matrix_print(A);
    printf("\nB |\n===\n");
    Matrix_print(B);

    Matrix *AB = Matrix_multiply(A, B);

    printf("\n A x B = \n");
    Matrix_print(AB);






    return 0;
}