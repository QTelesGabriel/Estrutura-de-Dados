#include <stdio.h>

void exibirMat (int lin, int col, int mat[lin][col]) {
    int i, j;
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            printf("mat[%d][%d]: %d\n", i, j, mat[i][j]);
        }
    }
}

void zerarDiv3 (int lin, int col, int mat[lin][col]) {
    int i, j;
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++ ) {
            if (mat[i][j] % 3 == 0) {
                mat[i][j] = 0;
            }
        }
    }
}

void exemplo3() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    zerarDiv3(3, 3, mat);
    exibirMat(3, 3, mat);
}

int main() {
    
    exemplo3();

    return 0;
}