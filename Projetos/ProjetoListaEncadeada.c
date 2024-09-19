//Lista encadeada

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

void inserirFim(t_lista *lista, int valor);
void inserirInicio(t_lista *lista, int valor);
void deletarFim(t_lista *lista);
void deletarInicio(t_lista *lista);
void inserirOrdenado(t_lista *lista, int valor);

int main() {
    t_lista lista;
    inicializarLista(&lista);

    inserirInicio(&lista, 3);
    listarLista(&lista);

    inserirFim(&lista, 5);
    listarLista(&lista);
    
    inserirOrdenado(&lista, 4);
    listarLista(&lista);

    inserirInicio(&lista, 0);
    listarLista(&lista);

    deletarFim(&lista);
    listarLista(&lista);

    deletarInicio(&lista);
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
    printf("Lista: ");
    while (aux != NULL) {
        printf("(%d)->", aux->valor);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void inserirFim(t_lista *lista, int valor) {
    if (!lista) {
        fprintf(stderr, "Lista inválida!\n");
        return;
    }
    t_no *novo_no = criarNo(valor);
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

void inserirInicio(t_lista *lista, int valor) {
    if (!lista) {
        fprintf(stderr, "Lista inválida!\n");
        return;
    }
    t_no *novo_no = criarNo(valor);
    if (!novo_no) {
        fprintf(stderr, "Erro ao criar novo nó!\n");
        return;
    }
    novo_no->prox = lista->primeiro;
    lista->primeiro = novo_no;
    if (lista->ultimo == NULL) {
        lista->ultimo = novo_no;
    }
    lista->size++;
}

void deletarFim(t_lista *lista) {
    if (!lista) {
        fprintf(stderr, "Lista inválida!\n");
        return;
    }
    if (!lista->primeiro) {
        printf("Lista vazia!\n");
        return;
    }
    if (!lista->primeiro->prox) {
        free(lista->primeiro);
        lista->primeiro = NULL;
        lista->ultimo = NULL;
    }
    else {
        t_no *aux = lista->primeiro;
        while (aux->prox->prox != NULL) {
            aux = aux->prox;
        }
        free(aux->prox);
        aux->prox = NULL;
        lista->ultimo = aux;
    }
    lista->size--;
}

void deletarInicio(t_lista *lista) {
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

void inserirOrdenado(t_lista *lista, int valor) {
    if(!lista) {
        fprintf(stderr, "Lista inválida!\n");
        return;
    }

    t_no *novo_no = criarNo(valor);
    if (!novo_no) {
        fprintf(stderr, "Erro ao criar novo nó!\n");
        return;
    }

    if (lista->primeiro == NULL || valor < lista->primeiro->valor) {
        novo_no->prox = lista->primeiro;
        lista->primeiro = novo_no;

        if (lista->ultimo == NULL) {
            lista->ultimo = novo_no;
        }

        lista->size++;
        return;
    }

    t_no *anterior = NULL;
    t_no *atual = lista->primeiro;

    while (atual != NULL && valor >= atual->valor) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = novo_no;
    novo_no->prox = atual;

    if (novo_no->prox == NULL) {
        lista->ultimo = novo_no;
    }

    lista->size++;
}