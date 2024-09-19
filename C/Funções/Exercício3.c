#include <stdio.h>

typedef struct Data {
    int dia, ano;
    char mes[12];
} t_data;

typedef struct {
    unsigned char a, b, g, r;
} t_rgba;

typedef union {
    int pixel;
    t_rgba rgba;
} u_pixel1;

typedef union {
    int pixel;
    char rgba[4];
} u_pixel2;

typedef struct Pessoa {
    char nome[100];
    int idade;
    float salario;
    t_data data_nasc;
} t_pessoa;

int main(void) {
    

    return 0;

}