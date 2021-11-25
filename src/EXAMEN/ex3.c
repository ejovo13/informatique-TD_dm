#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool first_iter = false;


void print_perm(const int * __arr, int __n, const int* __prev, int __base_n, int __prev_i) {

    int iter_count = __base_n - __n;

    if (__n == 1) {
        printf("%d ", __arr[0]);
    } else {

        for (int i = 0; i < __n ; i++) {

            if (iter_count > 0 && i > 0) {
                for (size_t j = 0; j < iter_count; j++) {

                    printf("%d ", __prev[__prev_i + j]); // black magic
                    // printf("%d ", __prev[j + __prev_i]); // black magic
                    // printf("%d ", (quitter_element(__prev, __base_n, j))[__prev_i + j]); // black magic
                }
            }

            printf("%d ", __arr[i]);
            print_perm(quitter_element(__arr, __n, i), __n - 1, __prev, __base_n, i);

            printf("\n");

        }
    }

}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6};
    int * b = quitter_element(arr, 3, 1);

    printf("\nPermutations: \n");

    print_perm(arr, 3, arr, 3, 0);

}