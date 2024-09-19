/*Utilizando *malloc, escreva um programa que aloque dinamicamente um array de float de 15 posições*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    float *num;
    num = (float *) malloc(15 * sizeof(float));

    if(!num) {
        printf("Não possui espaço");
        return 1;
    }

    free(num);
    
    return 0;
}