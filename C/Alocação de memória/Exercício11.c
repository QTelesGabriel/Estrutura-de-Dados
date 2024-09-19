/*Utilizando *realloc, escreva um programa que realoque dinamicamente um array de 20 estruturas do tipo pessoa, expandida com mais 5 posições, com os seguintesatributos:
• nome: String de 100 posições.
• idade: inteiro positivo.
• salário: real*/

#include <stdio.h>
#include <stdlib.h>

struct Pessoa {
    char nome[100];
    int idade;
    float salario;
};

int main() {
    struct Pessoa *pessoa;
    pessoa = (struct Pessoa *) calloc(20, sizeof(struct Pessoa *));
    if(!pessoa) {
        printf("Falha");
        return 1;
    }

    pessoa = (struct Pessoa *) realloc(pessoa, 25 * sizeof(struct Pessoa *));
    if(!pessoa) {
        printf("Falha");
        return 1;
    }

    free(pessoa);

    return 0;
}