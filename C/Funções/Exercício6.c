#include <stdio.h>

/*Para passar parametros em C é necessário usar ponteiros*/
void troca(int *p1, int *p2) {
    int aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

int main() {

    int a, b;
    a = 5;
    b = 3;

    int *p1 = &a;
    int *p2 = &b;

    troca(p1, p2);

    printf("a: %d / b: %d", a, b);

    return 0;
}