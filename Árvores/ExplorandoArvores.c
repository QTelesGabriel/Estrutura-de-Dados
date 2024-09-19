#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esquerdo;
    struct no *direito;
} t_no;


t_no *criarNo(int dado) {
    t_no *no = malloc(sizeof(t_no));
    if (no) {
        no->esquerdo = NULL;
        no->direito = NULL;
        no->dado = dado;
    }
    return no;
}

void exibir_pre_ordem(t_no *raiz) {
    if (raiz) {
        printf("%d ", raiz->dado);
        exibir_pre_ordem(raiz->esquerdo);
        exibir_pre_ordem(raiz->direito);
    }
}

int altura(t_no *raiz) {
    if (!raiz) {
        return 0;
    }
    if (raiz->esquerdo != NULL || raiz->direito != NULL) {
        if (altura(raiz->esquerdo) >= altura(raiz->direito)) {
            return altura(raiz->esquerdo) + 1;
        }
        else {
            return altura(raiz->direito) + 1;
        }
    }
    return 0;
}

t_no *menor_ancestral_comum(t_no *raiz, int v1, int v2) {
    if (!raiz) {
        return NULL;
    }
    if (raiz->esquerdo != NULL || raiz->direito != NULL) {
        if ((v1 < raiz->dado && v2 > raiz->dado) || (v1 > raiz->dado && v2 < raiz->dado)) {
            return raiz;
        }
        if (v1 > raiz->dado && v2 > raiz->dado) {
            return menor_ancestral_comum(raiz->direito, v1, v2);
        }
        if (v1 < raiz->dado && v2 < raiz->dado) {
            return menor_ancestral_comum(raiz->esquerdo, v1, v2);
        }
    }
    return NULL;
}

void deletar_no(t_no **raiz, int valor) {
    if (!(*raiz)) {
        return;
    }
    if ((*raiz)->dado != valor) {
        deletar_no(&((*raiz)->esquerdo), valor);
        deletar_no(&((*raiz)->direito), valor);
    }
    if ((*raiz)->dado == valor) {
        *raiz = NULL;
    }
}

int main() {
    t_no *raiz = criarNo(9);

    raiz->esquerdo = criarNo(7);
    raiz->direito = criarNo(12);

    if (raiz->esquerdo) {
        raiz->esquerdo->esquerdo = criarNo(5);
        raiz->esquerdo->direito = criarNo(8);
    }    
    if (raiz->direito) {
        raiz->direito->esquerdo = criarNo(10);
        raiz->direito->direito = criarNo(25);
    }

    if (raiz->direito->direito) {
        raiz->direito->direito->esquerdo = criarNo(15);
    }

    // ALTURA
    printf("Altura: %d\n", altura(raiz));

    // MENOR ANCESTRAL COMUM
    t_no *aux = menor_ancestral_comum(raiz, 10, 15);
    printf("Menor ancestral anterior: %d\n", aux->dado);

    // DELETAR NÓ
    t_no **raiz2 = &raiz;

    exibir_pre_ordem(raiz);
    printf("\n");
    deletar_no(raiz2, 7);
    exibir_pre_ordem(raiz);
    printf("\n");

    return 0;
}