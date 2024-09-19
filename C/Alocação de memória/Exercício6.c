/*Utilizando *calloc, escreva um programa que aloque dinamicamente um inteiro*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *inteiro = (int *) calloc(1, sizeof(int));

    if(!inteiro) {
        printf("Falha na alocação!");
        return 1;
    }

    free(inteiro);

    return 0;
}