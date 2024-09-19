/*Utilizando *calloc, escreva um programa que aloque dinamicamente uma string de 100 posições. (Lembre de incluir o ’\0’).*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *string;
    string = (char *) calloc(100, sizeof(char));

    if (!string) {
        printf("Falha na alocação dinâmica");
        return 1;
    }

    free(string);

    return 0;
}