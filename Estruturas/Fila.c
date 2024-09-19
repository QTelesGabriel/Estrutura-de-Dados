//Fila

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} t_no;

typedef struct {
    t_no *primeiro;
    t_no *ultimo;
    int size;
} t_lista;

void inicializarLista(t_lista *lista);
void listarLista(t_lista *lista);
t_no *criarNo(int valor);

void enfileira(t_lista *lista, int info);
void desenfileira(t_lista *lista);

int main() {
    t_lista lista;

    printf("<---Começo   /   Fim--->\n\n");
    inicializarLista(&lista);

    enfileira(&lista, 10);
    listarLista(&lista);

    desenfileira(&lista);
    listarLista(&lista);
    
    enfileira(&lista, 11);
    listarLista(&lista);
    
    enfileira(&lista, 12);
    listarLista(&lista);
    
    enfileira(&lista, 13);
    listarLista(&lista);

    desenfileira(&lista);
    listarLista(&lista);
    
    desenfileira(&lista);
    listarLista(&lista);
    
    desenfileira(&lista);
    listarLista(&lista);

    return 0;
}

t_no *criarNo(int valor) {
    t_no *novo_no = malloc(sizeof(t_no));
    if (novo_no) {
        novo_no->valor = valor;
        novo_no->prox = NULL;
    }
    return novo_no;
}

void inicializarLista(t_lista *lista) {
    lista->size = 0;
    lista->primeiro = NULL;
    lista->ultimo = NULL;
}

void listarLista(t_lista *lista) {
    t_no *aux = lista->primeiro;
    while (aux != NULL) {
        printf("(%d)->", aux->valor);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void enfileira(t_lista *lista, int info) {
    if (!lista) {
        fprintf(stderr, "Lista inválida!\n");
        return;
    }
    t_no *novo_no = criarNo(info);
    if (!novo_no) {
        fprintf(stderr, "Erro ao criar novo nó!\n");
        return;
    }
    if (lista->primeiro == NULL) {
        lista->primeiro = novo_no;
        lista->ultimo = novo_no;
    }
    else {
        lista->ultimo->prox = novo_no;
        lista->ultimo = novo_no;
    }
    lista->size++;
}

void desenfileira(t_lista *lista) {
    if (!lista) {
        fprintf(stderr, "Lista inválida!\n");
        return;
    }
    if (!lista->primeiro) {
        printf("Lista vazia!\n");
        return;
    }
    t_no *primeiro = lista->primeiro;
    t_no *novo_primeiro = primeiro->prox;
    free(primeiro);
    lista->primeiro = novo_primeiro;
    if (novo_primeiro == NULL) {
        lista->ultimo = NULL;
    }
    lista->size--;
}