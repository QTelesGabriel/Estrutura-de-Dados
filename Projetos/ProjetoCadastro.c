#include <stdio.h>
#include <stdlib.h>

#define OFFSET 10

typedef unsigned int uint;

typedef struct {
  int id;
  char nome[100];
  int idade;
  char genero;
} Pessoa;

typedef struct {
  uint size;
  uint limite;
  Pessoa *pessoas;
} Vetor;

void zerar(Vetor *vetor);
void inicializar(Vetor *vetor, int limite);
void inserirFim(Vetor *vetor, Pessoa p);
void listar(Vetor *vetor);

// Implemente as seguintes funções
void inserirInicio(Vetor *vetor, Pessoa p);
void inserirIndice(Vetor *vetor, int indice, Pessoa p);
void inserirOrdenadoPorIdade(Vetor *vetor, Pessoa p, int idade);
void inserirOrdenadoPorNome(Vetor *vetor, Pessoa p, char *nome);
void deletarInicio(Vetor *vetor);
void deletarFim(Vetor *vetor);
void deletarIndice(Vetor *vetor, int indice);
void deletarPorNome(Vetor *vetor, char *nome);
void atualizarIndice(Vetor *vetor, int indice, Pessoa p);
void atualizarPorNome(Vetor *vetor, Pessoa p, char *nome);

int main(void) {
  Vetor vetor;
  inicializar(&vetor, 11);
  inserirFim(&vetor, (Pessoa){.id = 1, .nome = "Ana", .idade = 25, .genero = 'F'});
  inserirFim(&vetor, (Pessoa){2, "Beto", 25, 'M'});
  inserirFim(&vetor, (Pessoa){3, "Caio", 25, 'M'});
  inserirFim(&vetor, (Pessoa){4, "Dani", 25, 'F'});
  inserirFim(&vetor, (Pessoa){5, "Fabio", 25, 'M'});
  inserirFim(&vetor, (Pessoa){6, "Gabi", 25, 'F'});
  inserirOrdenadoPorNome(&vetor, (Pessoa){7, "Daay", 25, 'M'}, "Daay");
  deletarPorNome(&vetor, "Caio");
  atualizarPorNome(&vetor, (Pessoa){6, "Daniel", 25, 'F'}, "Dani");
  atualizarIndice(&vetor, 3, (Pessoa){3, "João", 22, 'F'});
  inserirOrdenadoPorIdade(&vetor, (Pessoa){7, "Gabriel", 25, 'M'}, 25);
  deletarFim(&vetor);
  deletarIndice(&vetor, 3);
  inserirIndice(&vetor, 5, (Pessoa){.id = 1, .nome = "Vitor", .idade = 25, .genero = 'F'});
  inserirInicio(&vetor, (Pessoa){6, "joao", 25, 'F'});

  listar(&vetor);
  return 0;
}

void inicializar(Vetor *vetor, int limite) {
  vetor->size = 0; // (*vetor).size = 0;
  vetor->limite = limite;
  vetor->pessoas = malloc(sizeof(Pessoa) * limite);
}

void inserirFim(Vetor *vetor, Pessoa p) {
  // restrição da função
  if(vetor->size >= vetor->limite) {
    vetor->pessoas = realloc(vetor->pessoas, OFFSET);
  }
  vetor->pessoas[vetor->size] = p;
  vetor->size++;
}

void listar(Vetor *vetor) {
  for(int i = 0; i < (int)vetor->size; i++) {
    printf("Pessoa %d: (id: %d, nome: %s, idade: %d, genero: %c)\n"
            , i
            , vetor->pessoas[i].id
            , vetor->pessoas[i].nome
            , vetor->pessoas[i].idade
            , vetor->pessoas[i].genero
    );
  } 
}

void zerar(Vetor *vetor) {
  vetor->size = 0;
}

void inserirInicio(Vetor *vetor, Pessoa p) {
  if (vetor->size >= vetor->limite) {
    vetor->pessoas = realloc(vetor->pessoas, OFFSET);
  }
  for (int i = vetor->size; i >= 0; i--) {
    vetor->pessoas[i+1] = vetor->pessoas[i];
  }
  vetor->pessoas[0] = p;
  vetor->size++;
}

void inserirIndice(Vetor *vetor, int indice, Pessoa p) {
  if (vetor->size >= vetor->limite) {
    vetor->pessoas = realloc(vetor->pessoas, OFFSET);
  }
  for (int i = vetor->size; i >= indice; i--) {
    vetor->pessoas[i+1] = vetor->pessoas[i];
  }
  vetor->pessoas[indice] = p;
  vetor->size++;
}

void deletarInicio(Vetor *vetor) {
  for (int i = 1; i <= (int)vetor->size; i++) {
    vetor->pessoas[i-1] = vetor->pessoas[i];
  }
  vetor->size--;
}

void deletarFim(Vetor *vetor) {
  vetor->size--;
}

void deletarIndice(Vetor *vetor, int indice) {
  for (int i = indice; i <= (int)vetor->size; i++) {
    vetor->pessoas[i-1] = vetor->pessoas[i];
  }
  vetor->size--;
}

void inserirOrdenadoPorIdade(Vetor *vetor, Pessoa p, int idade) {
  if(vetor->size >= vetor->limite) {
    vetor->pessoas = realloc(vetor->pessoas, OFFSET);
  }
  
  int indice;
  int inicio = 0;
  int fim = vetor->size;

  while (inicio <= fim) {
    indice = inicio + (fim - inicio) / 2;

    if (idade == vetor->pessoas[indice].idade) {
      break;
    }

    else if (vetor->pessoas[indice].idade < idade) {
      inicio = indice + 1;
    }

    else if (vetor->pessoas[indice].idade > idade) {
      fim = indice - 1;
    }
  }

  //Sobrescrever os valores
  for (int i = vetor->size; i >= indice; i--) {
    vetor->pessoas[i+1] = vetor->pessoas[i];
  }
  vetor->pessoas[indice] = p;
  vetor->size++;
}

void atualizarIndice(Vetor *vetor, int indice, Pessoa p) {
  vetor->pessoas[indice] = p;
}

void atualizarPorNome(Vetor *vetor, Pessoa p, char *nome) {
  int semelhante;
  int i, j;
  int quantidade_letras_nome = 0;
  int indice;
    
  for (i = 0; nome[i] != '\0'; i++) {
    quantidade_letras_nome++;
  }
  
  
  for(i = 0; i < (int)vetor->size; i++) {
    semelhante = 0;
    for(j = 0; j < quantidade_letras_nome; j++) {
      if(nome[j] != vetor->pessoas[i].nome[j]) {
        semelhante = 1;
        break;
      }
    }
    if(semelhante == 0) {
      indice = i;
    }
  }

  vetor->pessoas[indice] = p;
}

void deletarPorNome(Vetor *vetor, char *nome) {
  int semelhante;
  int i, j;
  int quantidade_letras_nome = 0;
  int indice;
    
  for (i = 0; nome[i] != '\0'; i++) {
    quantidade_letras_nome++;
  }
  
  
  for(i = 0; i < (int)vetor->size; i++) {
    semelhante = 0;
    for(j = 0; j < quantidade_letras_nome; j++) {
      if(nome[j] != vetor->pessoas[i].nome[j]) {
        semelhante = 1;
        break;
      }
    }
    if(semelhante == 0) {
      indice = i;
    }
  }

  for (int i = indice + 1; i <= (int)vetor->size; i++) {
    vetor->pessoas[i-1] = vetor->pessoas[i];
  }
  vetor->size--;
}

void inserirOrdenadoPorNome(Vetor *vetor, Pessoa p, char *nome) {
  if(vetor->size >= vetor->limite) {
    vetor->pessoas = realloc(vetor->pessoas, OFFSET);
  }
  
  int indice;
  int inicio = 0;
  int fim = vetor->size;
  int pos_letra = 0;

  while (inicio <= fim) {
    indice = inicio + (fim - inicio) / 2;

    if ((int)(vetor->pessoas[indice].nome[pos_letra]) < (int)(nome[pos_letra])) {
      inicio = indice + 1;
    }

    else if ((int)(vetor->pessoas[indice].nome[pos_letra]) > (int)(nome[pos_letra])) {
      fim = indice - 1;
    }

    else if ((int)(nome[pos_letra]) == (int)(vetor->pessoas[indice].nome[pos_letra])) {
      while((int)(vetor->pessoas[indice].nome[pos_letra]) == (int)(nome[pos_letra])) {
        pos_letra++;
        if((int)(vetor->pessoas[indice].nome[pos_letra]) > (int)(nome[pos_letra])) {
          break;
        }
        else if ((int)(vetor->pessoas[indice].nome[pos_letra]) < (int)(nome[pos_letra])) {
          indice++;
        }
      }
      break;
    }

  }
  
  for (int i = vetor->size; i >= indice; i--) {
    vetor->pessoas[i+1] = vetor->pessoas[i];
  }
  vetor->pessoas[indice] = p;
  vetor->size++;
}