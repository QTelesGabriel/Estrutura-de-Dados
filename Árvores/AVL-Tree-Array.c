#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

int arvore[MAX_SIZE];

int filhoEsquerdo(int i) {
    return 2*i + 1;
}

int filhoDireito(int i) {
    return 2*i + 2;
}

void inserir(int dado, int pos) {
    if (pos < MAX_SIZE) {
        arvore[pos] = dado;
    } else {
        printf("Árvore cheia!\n");
    }
}

int noPai(int i) {
    return (i - 1) / 2;
}

void exibirArvorePorAltura() {
    int nivelAtual = 0;

    for (int i = 0; i < MAX_SIZE && arvore[i] != -1; i++) {
        int nivel = (int)log2(i + 1);

        if (nivel > nivelAtual) {
            printf("\n");  // Muda para o próximo nível da árvore
            nivelAtual = nivel;
        }

        printf("%d ", arvore[i]);  // Exibe o valor do nó
    }

    printf("\n");
}

void exibirArvoreDescendoPelosFilhosDaEsquerdaParaADireita(int i) {
    if (i >= MAX_SIZE || arvore[i] == -1)
        return;
    printf("%d ", arvore[i]);
    exibirArvoreDescendoPelosFilhosDaEsquerdaParaADireita(filhoEsquerdo(i));
    exibirArvoreDescendoPelosFilhosDaEsquerdaParaADireita(filhoDireito(i));
}

int main() {
    
    for (int i = 0; i < MAX_SIZE; i++) {
        arvore[i] = -1;  // Inicializa a árvore com -1, indicando que o nó está vazio
    }

    // Insere alguns dados na árvore para teste
    for (int i = 0; i < 15; i++) {
        arvore[i] = i + 1;
    }

    printf("\n");
    printf("Raiz: %d\n", arvore[0]);
    printf("Filho esquerdo da raiz: %d\n", arvore[filhoEsquerdo(0)]);
    printf("Filho direito da raiz: %d\n", arvore[filhoDireito(0)]);
    printf("\n");

    printf("Exibindo a arvore por altura:\n");
    exibirArvorePorAltura();

    printf("\nExibindo a arvore descendo pelos filhos da esquerda para a direita:\n");
    exibirArvoreDescendoPelosFilhosDaEsquerdaParaADireita(0);
    printf("\n\n");

    return 0;
}