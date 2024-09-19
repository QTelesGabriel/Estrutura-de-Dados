#include<stdio.h>
#include<stdlib.h>

enum cor {VERMELHO, PRETO};

typedef struct No {
  int dado;
  enum cor cor;
  struct No *esquerda, *direita, *pai;
} No;

No *raiz = NULL;

No* novoNo(int dado) {
  No *novo = (No*)malloc(sizeof(No));
  novo->dado = dado;
  novo->esquerda = novo->direita = novo->pai = NULL;
  novo->cor = VERMELHO;
  return novo;
}

void rotacaoEsquerda(No **raiz, No *x) {
  No *y = x->direita;
  x->direita = y->esquerda;
  if (x->direita != NULL)
    x->direita->pai = x;
  y->pai = x->pai;
  if (x->pai == NULL)
    (*raiz) = y;
  else if (x == x->pai->esquerda)
    x->pai->esquerda = y;
  else
    x->pai->direita = y;
  y->esquerda = x;
  x->pai = y;
}

void rotacaoDireita(No **raiz, No *y) {
  No *x = y->esquerda;
  y->esquerda = x->direita;
  if (x->direita != NULL)
    x->direita->pai = y;
  x->pai = y->pai;
  if (y->pai == NULL)
    (*raiz) = x;
  else if (y == y->pai->esquerda)
    y->pai->esquerda = x;
  else
    y->pai->direita = x;
  x->direita = y;
  y->pai = x;
}

void corrigirCor(No **raiz, No *z) {
  while (z != *raiz && z->pai->cor == VERMELHO) {
    if (z->pai == z->pai->pai->esquerda) {
      No *y = z->pai->pai->direita;
      if (y != NULL && y->cor == VERMELHO) {
        z->pai->cor = PRETO;
        y->cor = PRETO;
        z->pai->pai->cor = VERMELHO;
        z = z->pai->pai;
      } else {
        if (z == z->pai->direita) {
          z = z->pai;
          rotacaoEsquerda(raiz, z);
        }
        z->pai->cor = PRETO;
        z->pai->pai->cor = VERMELHO;
        rotacaoDireita(raiz, z->pai->pai);
      }
    } else {
      No *y = z->pai->pai->esquerda;
      if (y != NULL && y->cor == VERMELHO) {
        z->pai->cor = PRETO;
        y->cor = PRETO;
        z->pai->pai->cor = VERMELHO;
        z = z->pai->pai;
      } else {
        if (z == z->pai->esquerda) {
          z = z->pai;
          rotacaoDireita(raiz, z);
        }
        z->pai->cor = PRETO;
        z->pai->pai->cor = VERMELHO;
        rotacaoEsquerda(raiz, z->pai->pai);
      }
    }
  }
  (*raiz)->cor = PRETO;
}

void inserir(No **raiz, int dado) {
  No *z = novoNo(dado);
  No *y = NULL;
  No *x = (*raiz);

  while (x != NULL) {
    y = x;
    if (z->dado < x->dado)
      x = x->esquerda;
    else
      x = x->direita;
  }
  z->pai = y;
  if (y == NULL)
    (*raiz) = z;
  else if (z->dado < y->dado)
    y->esquerda = z;
  else
    y->direita = z;

  if (z->pai == NULL){
    z->cor = PRETO;
    return;
  }

  if (z->pai->pai == NULL)
    return;

  corrigirCor(raiz, z);
}

void emOrdem(No *raiz) {
  if (raiz == NULL)
    return;
  emOrdem(raiz->esquerda);
  printf("%d ", raiz->dado);
  emOrdem(raiz->direita);
}

int main() {
  inserir(&raiz, 7);
  inserir(&raiz, 6);
  inserir(&raiz, 5);
  inserir(&raiz, 4);
  inserir(&raiz, 3);
  inserir(&raiz, 2);
  inserir(&raiz, 1);
  printf("Em ordem: ");
  emOrdem(raiz);
  return 0;
}