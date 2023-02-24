
/**
 * Exemplos de alocacao estatica de structs.
*/
#include <string.h>
#include <stdio.h>

struct aluno {
    int ra;
    char nome[100];
    char curso[20];
};

void print_aluno(struct aluno a) {
    printf("RA: %d\n", a.ra);
    printf("Nome: %s\n", a.nome);
    printf("Curso: %s\n", a.curso);
}

int main(int argc, char const *argv[])
{
    struct aluno a1;

    a1.ra = 123;
    strcpy(a1.nome, "Joao Silva");
    strcpy(a1.curso, "BCC");
    
    print_aluno(a1);

    struct aluno a2 = {
        .ra = 456,
        .nome = "Joana Siqueira",
        .curso = "BC&T"
    };

    print_aluno(a2);

    struct aluno a3;
    char temp;

    printf("RA: ");
    scanf("%d", &a3.ra);
    scanf("%c", &temp);
    printf("Nome: ");
    scanf("%[^\n]", a3.nome);
    scanf("%c", &temp);
    printf("Curso: ");
    scanf("%[^\n]", a3.curso);
    scanf("%c", &temp);

    print_aluno(a3);

    return 0;
}
