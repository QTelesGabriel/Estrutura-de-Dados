/*Utilizando *calloc, escreva um programa que aloque dinamicamente um array de 20 estruturas do tipo pessoa, com os seguintes atributos:
• nome: String de 100 posições.
• idade: inteiro positivo.
• salário: real*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa {
    char nome[100];
    int idade;
    float salario;
}t_pessoa;

int main() {
    t_pessoa *pessoa = (t_pessoa *) calloc(20, sizeof(t_pessoa *));

    if (!pessoa) {
        printf("Falha na alocação");
        return 1;
    }

    free(pessoa);

    return 0;
}