/*Utilizando *calloc, escreva um programa que aloque dinamicamente uma matriz 5x5 de inteiros*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matriz = (int**) calloc(5, sizeof(int*));
    if(!matriz) {
        printf("Falha na alocação");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        matriz[i] = (int *) calloc(5, sizeof(int));
        if(!matriz[i]) {
            printf("Falha na alocação dinâmica");
            return 1;
        }
    }

    for (int i = 0; i < 5; i++) {
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}