#include <stdio.h>

void hanoi(int __n, int __dep, int __med, int __fin) {
    // Move the first n-1 disks to the middle tower
    // move 1 disk to the end
    // move the n-1 disks to the end tower

    if (__n == 1) {
        // move the disk to the 3rd tower
        printf("(%d, %d)\n", __dep, __fin);
    } else {
        // move n - 1 disks to the middle
        hanoi(__n - 1, __dep, __fin, __med); // Man that's a mindfuck. We are using the final tower as a stepping stone to move
                                             // n-1 towers to the middle tower, in order to move the largest disk!!

        // then, move 1 disk to the end.
        printf("(%d, %d)\n", __dep, __fin);

        // finally, move n-1 disks from the MIDDLE TOWER to the end tower, using the first tower as a stepping stone
        hanoi(__n - 1, __med, __dep, __fin);
    }
}

int main() {

    printf("Welcome to the tower of Hanoi game. Please enter the number of towers you would like:  ");

    int n = 0;
    scanf("%d", &n);

    hanoi(n, 1, 2, 3);

    return 0;

}