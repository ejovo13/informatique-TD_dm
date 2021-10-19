// Leibniz method to calculate pi
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



#define MAX_ITERATIONS 1000000

size_t count_words(const char *__string);

double leibniz_pi(double __precision);

char ** decompose_string(const char * __string);