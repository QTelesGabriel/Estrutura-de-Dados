/*Utilizando ponteiros, realize a troca de valores entre as variáveis n1 e n2*/

#include <stdio.h>

int main(void) {
    int n1 = 3, n2 = 5;
    int *p_n1, *p_n2;

    p_n1 = &n1; 
    p_n2 = &n2;

    int aux;

    aux = *p_n2;
    *p_n2 = *p_n1;

    *p_n1 = aux;

	printf("n1: %d, n2: %d\n", n1, n2);
	return 0;
}