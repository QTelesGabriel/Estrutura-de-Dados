#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int info; // elemento da lista
	struct no *prox;
} t_no;

typedef struct lista {
	t_no *primeiro;
} t_lista;

void inicializarListaV1(t_lista *lista) {
  lista->primeiro = NULL;
}

t_lista inicializarListaV2() {
  t_lista lista = { .primeiro = NULL };
  return lista;
}

t_no *criar_no(int info) {
  t_no *novo_no = malloc(sizeof(t_no));
  if(novo_no) {
    novo_no->info = info;
    novo_no->prox = NULL;
  }
  return novo_no;
}

void inserirFim(t_lista *lista, int info) {
  if(!lista) { // lista == NULL
    fprintf( stderr, "Lista inválida!\n");
    return;
  }
  t_no *novo_no = criar_no(info);
  if(!novo_no) {
    fprintf( stderr, "Erro ao criar novo nó!\n");
    return;
  }
  // lista->primeiro: NULL
  // SAIDA: lista->primeiro: novo_no
  if(!lista->primeiro) {
    lista->primeiro = novo_no;
  } else {
    t_no *aux = lista->primeiro;
    while(aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = novo_no;
  }
}

void inserirInicio(t_lista *lista, int info) {
  if(!lista) { // lista == NULL
    fprintf( stderr, "Lista inválida!\n");
    return;
  }
  t_no *novo_no = criar_no(info);
  if(!novo_no) {
    fprintf( stderr, "Erro ao criar novo nó!\n");
    return;
  }
  novo_no->prox = lista->primeiro;
  lista->primeiro = novo_no;
}

void listar(t_lista *lista) {
  // Listar 
  // (5)->(3)->(6)->NULL
  t_no *aux = lista->primeiro;
  while(aux != NULL) {
    printf("(%d)->", aux->info);
    aux = aux->prox;
  }
  printf("NULL\n");
}

void deletarInicio(t_lista *lista) {
  if(!lista) { // lista == NULL
    fprintf( stderr, "Lista inválida!\n");
    return;
  }
  if(!lista->primeiro) {
    printf("Lista vazia!\n");
    return;
  }
  t_no *primeiro = lista->primeiro;
  t_no *novo_primeiro = primeiro->prox;
  free(primeiro);
  lista->primeiro = novo_primeiro;
}

void deletarFim(t_lista *lista) {
  if(!lista) { // lista == NULL
    fprintf( stderr, "Lista inválida!\n");
    return;
  }
  if(!lista->primeiro) {
    printf("Lista vazia!\n");
    return;
  }
  if(!lista->primeiro->prox) {
    free(lista->primeiro);
    lista->primeiro = NULL;
  } else {
    t_no *aux = lista->primeiro;
    while(aux->prox->prox != NULL) {
      aux = aux->prox;
    }
    free(aux->prox);
    aux->prox = NULL;
  }
}

int main(void) {
  t_lista lista = inicializarListaV2();
  // lista.primeiro = criar_no(5);
  // lista.primeiro->prox = criar_no(3);
  // lista.primeiro->prox->prox = criar_no(6);
  listar(&lista);
  inserirInicio(&lista, 5);
  listar(&lista);
  inserirInicio(&lista, 3);
  listar(&lista);
  inserirInicio(&lista, 6);
  listar(&lista);
  inserirInicio(&lista, 2);
  listar(&lista);
  deletarFim(&lista);
  listar(&lista);
  deletarFim(&lista);
  listar(&lista);
  deletarFim(&lista);
  listar(&lista);
  deletarFim(&lista);
  listar(&lista); 
  
  return 0;
}