#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa{
    char nome[50];
    int idade;
    char sexo;
} p[500];

void cadastrar(struct Pessoa *p, int contador);
void exibir(struct Pessoa *p, int contador);
void achar_indice(struct Pessoa *p, int contador);

int main() {
    system("clear");
    int contador = 0;
    int opcao;
    do {
        printf("***CADASTRO***\n\n");
        printf("1. Cadastrar\n2. Exibir cadastro\n3. Achar indice\n4. Sair\n");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao) {
            case 1:
                cadastrar(p, contador);
                contador++;
                printf("\n\n");
                break;
            case 2:
                exibir(p, contador);
                printf("\n\n");
                break;
            case 3:
                achar_indice(p, contador);
                printf("\n\n");
                break;
            case 4:
                printf("Saindo...");
                printf("\n\n");
                break;
            default:
                printf("Escolha uma opcao válida");
                printf("\n\n");
                break;
        }
    } while (opcao != 4);

    return 0;

}

void cadastrar(struct Pessoa *p, int contador) {
    system("clear");
    printf("Nome: ");
    scanf(" %50[^\n]", p[contador].nome);
    getchar();
    
    printf("\nIdade: ");
    scanf("%d", &p[contador].idade);
    getchar();
    
    printf("\nSexo(m/f): ");
    do {
        scanf("%c", &p[contador].sexo);
        getchar();
        if(p[contador].sexo != 'm' && p[contador].sexo != 'f') {
            printf("\nEscolha (m) ou (f): ");
        }
    } while (p[contador].sexo != 'm' && p[contador].sexo != 'f');
    printf("\nCadastro criado\nAperte enter para voltar ao menu\n");
    getchar();
    system("clear");
}

void exibir(struct Pessoa *p, int contador) {
    system("clear");
    int n;      /*Número do cadastro*/
    printf("Escolha um indice de cadastro: ");
    scanf("%d", &n);
    if(n <= contador) {
        printf("%s  -   %d  -   %c\n\n", p[n].nome, p[n].idade, p[n].sexo);   
    } else {
        printf("Indice invalido\n");
    }
    printf("Aperte enter para voltar ao menu\n");
    getchar();
    getchar();
    system("clear");
}

void achar_indice(struct Pessoa *p, int contador) {
    int i, j, k = 0;
    int semelhante;
    int num[500];
    char procurar[50];
    
    system("clear");
    printf("Digite um nome que deseja ser achado: ");
    scanf(" %50[^\n]", procurar);
    
    for(i = 0; i < contador; i++) {
        semelhante = 0;
        for(j = 0; j < (int)strlen(procurar); j++) {
            if(procurar[j] != p[i].nome[j]) {
                semelhante = 1;
                break;
            }
        }
        if(semelhante == 0) {
            num[k] = i;
            k++;
        }
    }
    
    for(i = 0; i < k; i++) {
        printf("%d ", num[i]);
    }
    
    printf("\n\nAperte enter para voltar ao menu\n");
    getchar();
    getchar();
    system("clear");
}

