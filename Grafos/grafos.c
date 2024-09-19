#include <stdio.h>
#include <stdlib.h>

struct Cidade {
  char nome[50];
};
typedef struct Cidade Cidade;

struct NoAresta {
  int destino;
  float peso;
  struct NoAresta *prox;
};
typedef struct NoAresta NoAresta;

struct ListaArestas {
  NoAresta *inicio;
};
typedef struct ListaArestas ListaArestas;

struct Grafo {
  int n;
  ListaArestas *arestas;
  Cidade *vertices;
};
typedef struct Grafo Grafo;

Grafo *criarGrafo(int n) {
  Grafo *grafo = malloc(sizeof(Grafo));
  if(grafo) {
    grafo->arestas = malloc(sizeof(ListaArestas) * n);
    grafo->vertices = malloc(sizeof(Cidade) * n);
    if(!grafo->arestas || !grafo->vertices) {
      free(grafo->arestas);
      free(grafo->vertices);
      free(grafo);
      return NULL;
    }
    grafo->n = n;
    for(int i = 0; i < n; i++) {
      grafo->arestas[i].inicio = NULL;
    }
  }
  return grafo;
}

void copiaString(char *origem, char *destino) {
  while(*origem != '\0') {
    *destino++ = *origem++;
  }
  *destino = '\0';
}

void atualizarVertice(Grafo *grafo, Cidade cidade, int indice) {
  copiaString(cidade.nome, grafo->vertices[indice].nome);
}

NoAresta *criarAresta(int destino, float peso) {
  NoAresta *aresta = malloc(sizeof(NoAresta));
  if(aresta) {
    aresta->destino = destino;
    aresta->peso = peso;
    aresta->prox = NULL;
  }
  return aresta;
}

void adicionarAresta(Grafo *grafo, int origem, int destino, float peso) {
  NoAresta *novaAresta = criarAresta(destino, peso);
  if(!novaAresta) {
    printf("Erro ao alocar memória.\n");
    return;
  }
  novaAresta->prox = grafo->arestas[origem].inicio;
  grafo->arestas[origem].inicio = novaAresta;
}

void imprimirGrafo(Grafo *grafo) {
  for(int i = 0; i < grafo->n; i++) {
    printf("Vértice %s: Arestas: ", grafo->vertices[i].nome);
    NoAresta *aux = grafo->arestas[i].inicio;
    while(aux) {
      printf("(%.1f) %s -> ", aux->peso, grafo->vertices[aux->destino].nome);
      aux = aux->prox;
    }
    printf("NULL\n");
  }
}

int main(void) {
  Grafo *grafo = criarGrafo(6);
  atualizarVertice(grafo, (Cidade){.nome = "Rio de Janeiro"}, 0);
  atualizarVertice(grafo, (Cidade){.nome = "São Paulo"}, 1);
  atualizarVertice(grafo, (Cidade){.nome = "Ribeirão Preto"}, 2);
  atualizarVertice(grafo, (Cidade){.nome = "Petrópolis"}, 3);
  atualizarVertice(grafo, (Cidade){.nome = "Ouro Preto"}, 4);
  atualizarVertice(grafo, (Cidade){.nome = "Bonito"}, 5);

  adicionarAresta(grafo, 0, 1, 60);
  adicionarAresta(grafo, 0, 2, 160);
  adicionarAresta(grafo, 0, 3, 20);
  
  adicionarAresta(grafo, 1, 2, 30);
  adicionarAresta(grafo, 1, 4, 50);
  
  adicionarAresta(grafo, 2, 4, 10);
  adicionarAresta(grafo, 2, 5, 40);
  
  adicionarAresta(grafo, 3, 5, 350);
  
  imprimirGrafo(grafo);
  
  return 0;
}