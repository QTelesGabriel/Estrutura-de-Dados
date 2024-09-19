/*Passagem de parâmetros para as funções*/

#include <stdio.h>

void linha_x(int num) {
    int i;
    for (i = 0; i < num; i++) {
        printf("*");
    }
    printf("\n");
}

int main() {
   
    linha_x(3);
    linha_x(5);
    linha_x(7);
    linha_x(5);
    linha_x(3);

    return 0;

}