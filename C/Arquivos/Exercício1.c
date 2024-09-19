#include <stdio.h>

int main() {
    FILE *fp;   // file pointer
    char s[100];
    printf("Introduza o nome do arquivo: ");
    scanf("%[^\n]%*c", s);
    /* Abrir o arquivo */
    fp = fopen(s, "r");
    /* Verificar se a abertura foi feita com sucesso */
    if (fp == NULL) {
        fprintf(stderr, "Impossível abrir o arquivo %s\n", s);
        return 1;
    }
    else {
        printf("Arquivo %s aberto com sucesso!\n", s);
        // realizar procedimentos de leitura do arquivo
        fclose(fp);    // necessário antes de terminar o programa
    }

    return 0;
}