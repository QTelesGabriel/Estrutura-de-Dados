//Pilha

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} t_no;

typedef struct {
    t_no *topo;
} t_pilha;

void iniciarPilha(t_pilha *pilha);
t_no *criar_no();
void push(t_pilha *pilha);
int top(t_pilha *pilha);
int pop(t_pilha *pilha);

int main() {
    t_pilha pilha;
    
    iniciarPilha(&pilha);
    push(&pilha);
    printf("%d\n", top(&pilha));
    pop(&pilha);
    push(&pilha);
    push(&pilha);
    int valor1 = pop(&pilha);
    printf("%d\n", valor1);
    int valor2 = pop(&pilha);
    printf("%d\n", valor2);
    pop(&pilha);

    return 0;
}

void iniciarPilha(t_pilha *pilha) {
    pilha->topo = NULL;
}

t_no *criar_no() {
    t_no *novo_no = (t_no *) calloc(1, sizeof(t_no));
    if (novo_no) {
        novo_no->prox = NULL;
    }
    return novo_no;
}

void push(t_pilha *pilha) {
    if(!pilha) {
        fprintf(stderr, "Pilha inválida!\n");
        exit(1);
    }
    
    t_no *novo_no = criar_no();
    if(!novo_no) {
        fprintf(stderr, "Erro ao criar novo nó!\n");
        return;
    }

    if(pilha->topo == NULL) {
        pilha->topo = novo_no;
    }
    else {
        novo_no->prox = pilha->topo;
        pilha->topo = novo_no;
    }

    return;
}


int top(t_pilha *pilha) {
    if(!pilha) {
        fprintf(stderr, "Pilha inválida!\n");
        exit(1);
    }
    int valor = pilha->topo->valor;
    return valor;
}

int pop(t_pilha *pilha) {
    if(!pilha->topo) {
        fprintf(stderr, "Pilha inválida!\n");
        exit(1);
    }
    int valor = pilha->topo->valor;

    t_no *temp = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(temp);

    return valor;
}