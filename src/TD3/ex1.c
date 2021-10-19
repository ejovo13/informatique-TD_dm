#include <stdio.h>

int main() {

    // 5 etats 0, 1, 2, 3, 4, et une speciale -1

    // can only write 1 and 0 on the tape

    // un tableau d'entier ruban de taille 100 thats the tape
    int tape[100] = {0};
    int pos = 50;
    int cstate = 0; // state of the machine
    int write0[5] = {1, 1, 1, 1, 1};
    int write1[5] = {0, 1, 0, 0, 0};
    int disp0[5] = {1, 1, 1, 1, -1}; // far clearer than the french "depl0" where the "L" looks like a "1"
    int disp1[5] = {-1, -1, -1, -1, 1};
    int nextstate0[5] = {1, 2, 3, 4, 3};
    int nextstate1[5] = {-1, 0, 1, 2, 4};

    // start the turing machine
    int t_count = 0;

    while (cstate != -1) {

        // read the tape
        if ( tape[pos] == 0 ) {
            printf("Tape read as 0\n");
            tape[pos] = write0[cstate];
            pos += disp0[cstate];
            cstate = nextstate0[cstate];
        } else if ( tape[pos] == 1 ) {
            printf("Tape read as 1\n");
            tape[pos] = write1[cstate];
            pos += disp1[cstate];
            cstate = nextstate1[cstate];
        } else { // something went wrong
            return 1;
        }

        t_count++;
    }

    printf("Number of turing steps: %d\n", t_count);

    return 0;
}