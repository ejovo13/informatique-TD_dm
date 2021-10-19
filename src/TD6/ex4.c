#include "TD6.h"

size_t count_words(const char *__string) {

    size_t n_words = 0;

    for (size_t i = 0; __string[i] != '\0'; i++) { // c++ style for loop but ugly lol

        if (__string[i] != ' ' && __string[i] != '\n' && __string[i] != '\t') { // If the current character is not a space
            // and next character is a space of null character
            if(__string[i + 1] == ' ' || __string[i + 1] == '\n' || __string[i + 1] == '\t') {
                n_words ++;
            }
        }
    }

    return n_words;

}

char ** decompose_string(const char *__string) {

    // decompose a string that is separated by spaces
    size_t len = strlen(__string);

    // count the words that exist in a string

    // a word can be separated by any number of spaces or tabs

    size_t n_words = count_words(__string);

    // Now that we know how many words there are, we can allocate the return array

    printf("Number of words: %lu\n", n_words);

    char ** word_table = (char **) malloc(sizeof(char *) * (n_words + 1));
    word_table[n_words] = NULL;

    if(word_table) {
        printf("Word table properly allocated\n");
    }

    // Let's start learning the words boundaries.
    size_t start_search_index = 0; // where to start searching for the first word index
    size_t start_index = 0; // start index of the current word
    size_t end_index = -1;
    size_t word_length = 0;
    for (size_t i = 0; i < n_words; i++) {
        // iterate through each word

        // For each word, I need to find the start and end bounds


        start_search_index = end_index + 1; // start searching where the final word ended
                                            // Don't tell anyone else this but this is super fucked up
                                            // because I'm actually storing end_index as an unsigned long
                                            // (size_t) but I'm setting the initial value to "-1". This obviously
                                            // overflows and wraps around, and adding 1 to this value brings us
                                            // back to 0. We NEED to include this plus 1 so that we start searching
                                            // after the last word's final character.


        // find the words starting index. This is to allow for sentences with multiple spaces in between words
        for (size_t k = start_search_index; k < len; k++) {
            if (__string[k] != ' ' && __string[k] != '\n') {
                start_index = k;
                break;
            }
        }

        printf("word %d start index: %lu\n", i+1, start_index);

        // iterate through each character of __string
        for (size_t j = start_index ; j < len; j++) {

           if (__string[j] != ' ' && __string[j] != '\n' && __string[j] != '\t') { // If the current character is not a space
            // and next character is a space or null character
                if(__string[j + 1] == ' ' || __string[j + 1] == '\n' || __string[j + 1] == '\t' || __string[j + 1] == '\0') {
                    printf("end_index set as: %lu\n", end_index);
                    end_index = j;
                    break;
                }
            }
        }

        // we've now found the word boundary. Compute the length of the word and allocate that amount of space
        word_length = end_index - start_index + 1;
        printf("word %d length: %lu\n", i, word_length);

        // allocate space for this word
        word_table[i] = (char *) malloc(sizeof(char) * (word_length + 1));

        // then fill this string
        for (size_t o = 0; o < word_length; o++) {
            word_table[i][o] = __string[start_index + o];
        }
        word_table[i][word_length] = '\0';
    }

    // free()
    return word_table;

}