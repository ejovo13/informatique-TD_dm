#include "TD2.h"

bool est_palindrome(const int * __T, size_t __N) {

    for (size_t i = 0; i < __N/2; i++) {
        if (__T[i] != __T[__N - i - 1]) return false;
    }

    return true;
}