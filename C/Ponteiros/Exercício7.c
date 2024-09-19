#include <stdio.h>
#include <string.h>

int main() {
    
    char palavra[5] = "Jonas";
    char palavra_copia[5];
    
    strcpy(palavra_copia, palavra);

    char *p_palavra = palavra_copia;
    int i;
    int j = 0;

    for (i = 4; i >= 0; i--) {
        palavra[j] = *(p_palavra + i);
        j++;
    }

    strcpy(palavra_copia, palavra);

    for (i = 0; i < 5; i++) {
        printf("%c\n", *(p_palavra + i));
    }  

    return 0;
}