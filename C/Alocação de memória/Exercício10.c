/*Utilizando *realloc, escreva um programa que realoque dinamicamente uma string de 100 posições, expandida com mais 50 posições. (Lembre de incluir o ’\0’)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *string = (char *) calloc(100, sizeof(char));
    if(!string) {
        printf("Falha");
        return 1;
    }

    strcpy(string, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    printf("%s\n", string);

    string = realloc(string, 150 * sizeof(char));
    if(!string) {
        printf("Falha");
        return 1;
    }
    strcpy(string, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    printf("%s\n", string);

    free(string);

    return 0;
}