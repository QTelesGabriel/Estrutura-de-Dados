#include <stdio.h>
#include <stdlib.h>

/*
Árvores de busca binária:
    Na árvore de busca binária, se o elemento a ser inserido for menor que o raíz, ele deverá ser colocado a esquerda
    No caso de ser maior, deve ser colocado a direita 


Ex: 
                32
              /    \ 
            18      47
           /  \    /  \ 
          6   21  40   50 

    A árvore pode estar desbalanceada, o que mudará o custo de memória
*/
         
typedef struct No {
    struct No *esq;
    struct No *dir;
    char valor;
} t_no;

void inicializarArvore(t_no *raiz) {
    if (!raiz) {
        fprintf(stderr, "Raiz inválida!\n");
        return;
    }
    raiz->esq = NULL;
    raiz->dir = NULL;
    raiz->valor = '\0';
}

t_no *criarNo(char valor) {
    t_no *no = malloc(sizeof(t_no));
    if (no) {
        no->esq = NULL;
        no->dir = NULL;
        no->valor = valor;
    }
    return no;
}

// As seguintes funções devem seguir algorítmos de recursão
// Na pre_ordem é necessário imprimir toda vez que o nó aparece pela primeira vez
// No in_ordem é necessário pecorrer até o final da esquerda para então imprimir o valor e seguir a sequência
// No pos_ordem é necessário pecorrer com recursão até ser a útlima vez a se passar pelo nó 

/*
             A
          /    \
        B       C
      /  \    /   \
     D    E  F     G

    Pré-ordem: A, B, D, E, C, F, G
    In-ordem: D, B, E, A, F, C, G
    Pós-ordem: D, E, B, F, G, C, A
*/

void exibir_pre_ordem(t_no *raiz) {
    if (raiz) {
        printf("%c ", raiz->valor);
        exibir_pre_ordem(raiz->esq);
        exibir_pre_ordem(raiz->dir);
    }
}

void exibir_in_ordem(t_no *raiz) {
    if (raiz) {
        exibir_in_ordem(raiz->esq);
        printf("%c ", raiz->valor);
        exibir_in_ordem(raiz->dir);
    }
}

void exibir_pos_ordem(t_no *raiz) {
    if (raiz) {
        exibir_pos_ordem(raiz->esq);
        exibir_pos_ordem(raiz->dir);
        printf("%c ", raiz->valor);
    }
}

void inserir_ord(t_no *raiz, char valor) {
    if (!raiz) {
        return;
    }

    if (valor < raiz->valor) {
        if (raiz->esq) {
            inserir_ord(raiz->esq, valor);
        }
        else {
            raiz->esq = criarNo(valor);
        }
    }
    else if (valor > raiz->valor) {
        if (raiz->dir) {
            inserir_ord(raiz->dir, valor);
        }
        else {
            raiz->dir = criarNo(valor);
        }
    }
}

void eliminar_arvore(t_no *raiz) {
    if (raiz) {
        eliminar_arvore(raiz->esq);
        eliminar_arvore(raiz->dir);
        free(raiz);
    }
}

int main() {
    t_no raiz;
    inicializarArvore(&raiz);
    raiz.valor = 'A';
    raiz.esq = criarNo('B');
    raiz.dir = criarNo('C');
    if (raiz.esq) {
        raiz.esq->esq = criarNo('D');
        raiz.esq->dir = criarNo('E');
    }
    if (raiz.dir) {
        raiz.dir->esq = criarNo('F');
        raiz.dir->dir = criarNo('G');
    }

    exibir_pre_ordem(&raiz);
    putchar('\n');
    exibir_in_ordem(&raiz);
    putchar('\n');
    exibir_pos_ordem(&raiz);

    return 0;
}