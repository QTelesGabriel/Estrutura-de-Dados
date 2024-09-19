#include <stdio.h>

int main() {
    int v[6] = {4, 3, 7, 5, 6, 2};
    int *pv;
    pv = (int *)v;

    int i;

    for (i = 0; i < 6; i++) {
        printf("%d\n", v[i]);
    }

    *(pv + 3) = 1;

    for (i = 0; i < 6; i++) {
        printf("%d\n", *(pv + i));
    }

    return 0;
}