// Leibniz method to calculate pi
#include "TD6.h"

double leibniz_pi(double __precision) {

    double plus_tolerance = sin(__precision); // sin(0) and sin(pi) are equal to 0.
    double minus_tolerance = sin(-__precision); // sin(0) and sin(pi) are equal to 0.

    double pi_4 = 0;
    int index = 0;

    while (true) {

        pi_4 += pow(-1.0, index)/((2 * index) + 1);
        index++;

        if( sin(pi_4 * 4.0) < plus_tolerance && sin(pi_4 * 4.0) > minus_tolerance) {
            if ( (pi_4 * 4.0) < 4 && (pi_4 * 4.0) > 3 ) {
                return pi_4;
            }
        }

        if ( index > MAX_ITERATIONS ) {
            break;
        }

    }
}

char ** decompose_string(const char * __string) {

    // decompose a string that is separated by spaces
    size_t len = strlen(__string);

    // count the words that exist in a string

    // a word can be separated by any number of spaces or tabs

    size_t n_words = 0;

    for (size_t i = 0; i < len; i++) {

        if (__string[i] != ' ' && __string[i] != '\n' && __string[i] != '\t') { // If the current character is not a space
            // and next character is a space of null character
            if(__string[i + 1] == ' ' || __string[i + 1] == '\n' || __string[i + 1] == '\t' || __string[i + 1] == '\0') {
                n_words ++;
            }
        }
    }

    // Now that we know how many words there are, we can allocate the return array

    char ** word_table = (char **) malloc(sizeof(char *) * (n_words + 1));
    word_table[n_words] = NULL;

    // Let's start learning the words boundaries.
    size_t start_index = 0;
    for (size_t i = 0; i < n_words; i++) {
        // iterate through each word
        for (size_t j = start_index ; j < len; j++) {
            // iterate through each character of __string
           if (__string[i] != ' ' && __string[i] != '\n' && __string[i] != '\t') { // If the current character is not a space
            // and next character is a space of null character
                if(__string[i + 1] == ' ' || __string[i + 1] == '\n' || __string[i + 1] == '\t' || __string[i + 1] == '\0') {
                    n_words ++;
                }
            }
        }
    }


    printf("string '%s' has %d words\n", __string, n_words);

}


