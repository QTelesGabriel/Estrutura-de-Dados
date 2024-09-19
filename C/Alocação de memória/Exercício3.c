/*Utilizando *malloc, escreva um programa que aloque dinamicamente uma string de 100 posições*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *string = (char *)malloc(100*sizeof(char));
    if(!string) {
        return 1;
    }

    free(string);

    return 0;
}