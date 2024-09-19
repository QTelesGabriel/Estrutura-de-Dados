/*Utilizando ponteiros, altere o conteúdo da variável numero para 5.*/

#include <stdio.h>

int main() {
    int numero;
    int *a;

    a = &numero;
    *a = 5;

    printf("%d\n", numero);
	
	return 0;
}