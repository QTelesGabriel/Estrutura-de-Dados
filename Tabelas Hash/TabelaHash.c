#include <stdio.h>

void preencher_tabela(int tabela_hash[128], char *texto) {
    int i = 0;
    while(texto[i] != '\0'){
        tabela_hash[(int)texto[i]] = 1;
        i++;
    }
}

int validar_input(int tabela_hash[128], char *input) {
    int i = 0;
    while(input[i] != '\0'){
        if(tabela_hash[(int)input[i]] == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    int tabela_hash[128] = {0};
    char *texto = "Alice";

    preencher_tabela(tabela_hash, texto);

    for(int i = 0; i < 128; i++) {
        if(i >= 32 && i < 127) {
            printf("%c : %d\n", i, tabela_hash[i]);
        }
        else {
            printf("  : %d\n", tabela_hash[i]);
        }
    }

    printf("\nValidade: %d\n\n", validar_input(tabela_hash, "AliceecA"));
    printf("\nValidade: %d\n\n", validar_input(tabela_hash, "ABDEFDSa"));

    return 0;
}