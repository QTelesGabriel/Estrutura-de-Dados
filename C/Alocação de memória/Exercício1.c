#include <stdio.h>
#include <stdlib.h>

int *build_int_array(unsigned int size) {
    return malloc(sizeof(int) * size);
}

float *medias_das_notas(int m, int n, float matriz[m][n]) {
    float *media = malloc(sizeof(float) * m);
    float soma = 0;
    for (int aluno = 0; aluno < m; aluno++) {
        soma = 0;
        for (int nota = 0; nota < n; nota++) {
            soma += matriz[aluno][nota];
        }
        media[aluno] = soma/n;
    }
    return media;
}

void exibir_array(int n, float arr[n]) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: %.2f\n", i, arr[i]);
    }
}

int main() {
    float mat[3][3] = {
        {7, 8, 9},     /*Aluno 0*/
        {5, 6, 7},     /*Aluno 1*/
        {4, 5, 6}      /*Aluno 2*/
    };

    float *media = medias_das_notas(3, 3, mat);
    exibir_array(3, media);

    return 0;
}