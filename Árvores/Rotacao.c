#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *dir, *esq;
} t_no;

t_no *criarNo(int dado) {
    t_no *no = (t_no *)malloc(sizeof(t_no));
    if (no) {
        no->esq = NULL;
        no->dir = NULL;
        no->dado = dado;
    }
    return no;
}

int altura(t_no *raiz) {
    if (!raiz) {
        return 0;
    }
    if (raiz->dir || raiz->esq) {
        if (altura(raiz->dir) >= altura(raiz->esq)) {
            return altura(raiz->dir) + 1;
        }
        else {
            return altura(raiz->esq) + 1;
        }
    }
    return 0;
}

t_no rotacao_esq(t_no *raiz) {
    t_no *dir = raiz->dir;
    raiz->dir = dir->esq;
    dir->esq = raiz;

    altura(dir);

    return *dir;
}

t_no rotacao_dir(t_no *raiz) {
    t_no *esq = raiz->esq;
    raiz->esq = esq->dir;
    esq->dir = raiz;

    altura(esq);
    
    return *esq;
}

int main() {
    t_no *raiz = criarNo(1);

    raiz->dir = criarNo(3);
    raiz->dir->esq = criarNo(2);
    raiz->dir->dir = criarNo(4);
}