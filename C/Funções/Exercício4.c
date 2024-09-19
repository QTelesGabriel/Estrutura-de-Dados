typedef struct Data {
    int dia, ano;
    char mes[12];
} t_data;

typedef struct Pessoa {
    char nome[100];
    int idade;
    float salario;
    struct Data data_nasc;
} t_pessoa;

int main(void) {
    t_pessoa p1;
    printf("Introduza a idade: ");
    scanf("%d", &p1.idade);
    printf("\nIntroduza o nome: ");
    scanf(" %100[^\n]", p1.nome);
    printf("\nIntroduza o salário: ");
    scanf("%f", &p1.salario);
    printf("\nIntroduza sua data de nascimento: ");
    scanf("%d de %s de %d", &p1.data_nasc.dia, p1.data_nasc.mes, &p1.data_nasc.ano);
    

    printf("\n%d, %s, %.2f\n%d/%s/%d", p1.idade, p1.nome, p1.salario, p1.data_nasc.dia, p1.data_nasc.mes, p1.data_nasc.ano);

    return 0;
}