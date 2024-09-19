#include <stdio.h>

int main() {

    int num[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };

    int lin, col;
    for (lin = 0; lin < 3; lin++) {
        for (col = 0; col < 4; col++) {
            printf("num[%d][%d]: %d\n", lin, col, num[lin][col]);
        }
    }

    int *ptr = (int *)num;
    int i;
    for (i = 0; i < 3 * 4; i++) {
        printf("n[%d]: %d\n", i, *(ptr + i));
    }
}