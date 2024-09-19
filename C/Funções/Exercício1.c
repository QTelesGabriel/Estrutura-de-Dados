#include <stdio.h>

void tres_caracteres() {
    printf("***\n");
}

void cinco_caracteres() {
    printf("*****\n");
}

void sete_caracteres() {
    printf("*******\n");
}

int main() {

    tres_caracteres();
    cinco_caracteres();
    sete_caracteres();
    cinco_caracteres();
    tres_caracteres();

    return 0;
}