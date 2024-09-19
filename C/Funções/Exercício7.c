#include <stdio.h>
#include <stdlib.h>

#define LIMITE 10

typedef unsigned int uint;

typedef struct {
    char nome[100];
    int idade;
    char genero;
} Pessoa;

typedef struct {
    uint size;
    uint limite;
    Pessoa pessoas[10];
} Vetor;

void inicializar(Vetor *vetor, int limite) {
    vetor->size = 0;        /*A seta serve para struct que envolver vetor*/
                            /*(*vetor).size = 0; ---> É equivalente a vetor->size = 0;*/
    if (limite > LIMITE) {
        printf("Limite inválido!\n");
        fprintf(stderr, "Limite inválido!\n");
        exit(1);
    }
    vetor->limite = limite;
}

void inserirFim(Vetor *vetor, Pessoa p) {
    if (vetor->size >= vetor->limite) {
        printf("Lista cheia!\n");
        return;
    }
    vetor->pessoas[vetor->size] = p;
    vetor->size += 1;
}

void inserirInicio(Vetor *vetor, Pessoa p) {
    
    int i;

    if (vetor->size >= vetor->limite) {
        printf("Lista cheia!\n");
        return;
    }
    
    for (i = vetor->size - 1; i >= 0; i--) {
        vetor->pessoas[i + 1] = vetor->pessoas[i];
    }

    vetor->size += 1;
    vetor->pessoas[0] = p;
}

void listar(Vetor *vetor) {
    int i;
    for(i = 0; i < vetor->size; i++) {
        printf("Pessoa %d: %s\n", i, vetor->pessoas[i].nome);
    }
}

int main() {
    Vetor vetor;
    vetor.size = 0;
    vetor.limite = LIMITE;
    inicializar(&vetor, 5);
    inserirFim(&vetor, (Pessoa){.nome = "Ana", .idade = 25, .genero = 'F'});
    inserirFim(&vetor, (Pessoa){.nome = "Cleiton", .idade = 24, .genero = 'M'});
    inserirInicio(&vetor, (Pessoa){.nome = "Ben10", .idade = 27, .genero = 'M'});
    inserirFim(&vetor, (Pessoa){.nome = "Cleber", .idade = 28, .genero = 'M'});
    inserirFim(&vetor, (Pessoa){.nome = "Oi", .idade = 22, .genero = 'M'});

    listar(&vetor);

    return 0;
}