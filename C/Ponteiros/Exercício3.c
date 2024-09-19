/*Dado o programa abaixo, utilize o ponteiro *c para acessar e imprimir na tela cada byte do inteiro rgba, correspondendo aos canais, r (01), g (02), b (03) e a, ou alfa, (FF).*/

#include <stdio.h>

int main() {
    int rgba = 0x010203FF;
	unsigned char *c = (unsigned char *) &rgba; /*Transforma &rgba em um unsigned char *. Por isso é necessário colocar o * no printf para aparecer os bytes corretamente*/

    /* r = 01, g = 02, b = 03, a = FF */

    printf("r = %02x\n", *(c + 3));
    printf("g = %02x\n", *(c + 2));
    printf("b = %02x\n", *(c + 1));
    printf("a = %02x\n", *(c));

	return 0;
}
