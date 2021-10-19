#include <stdio.h>
#include <stdlib.h>

int * quitter_element(const int * __arr, int __n, int __index) {

    int * new_arr = (int *) malloc(sizeof(int) * (__n - 1));

    int new_arr_i = 0;
    for (int i = 0; i < __n; i++) {

        if ( i == __index ) {
            continue;
        } else {
            new_arr[new_arr_i] = __arr[i];
            new_arr_i ++;
        }
    }

    return new_arr;

}

void print_perm(const int * __arr, int __n) {

    if (__n == 1) {
        printf("%d ", __arr[0]);
    } else {

        for (int i = 0; i < __n; i++) {
            // for (int j = 0; j < __n - 1; j++) {

                printf("%d ", __arr[i]);
                print_perm(quitter_element(__arr, __n, i), __n - 1);
                printf("\n");

                if ( __n > 2 ) {
                    printf("%d ", __arr[i]);
                }
            // }

            // printf("\n%d ", __arr[i]);
        }
    }
}

int main() {

    int arr[] = {1, 2, 3, 4};
    int * b = quitter_element(arr, 3, 1);

    for (int i = 0; i < 2; i++) {
        printf("%d ", b[i]);
    }
    int * c = quitter_element(arr, 3, 2);

    for (int i = 0; i < 2; i++) {
        printf("%d ", c[i]);
    }

    int * d = quitter_element(arr, 3, 0);

    for (int i = 0; i < 2; i++) {
        printf("%d ", d[i]);
    }

    printf("\nPermutations: \n");

    print_perm(arr, 3);

}