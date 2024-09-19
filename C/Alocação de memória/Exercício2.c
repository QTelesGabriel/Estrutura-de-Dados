/*Utilizando *malloc, escreva um programa que aloque dinamicamente um inteiro*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *num = (int *)malloc(sizeof(int*));
    return 0;   
}