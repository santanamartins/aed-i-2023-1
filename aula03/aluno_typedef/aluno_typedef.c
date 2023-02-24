/**
 * Exemplo de uso de typedef para simplificar o uso 
 * de structs (usamos aluno_t ao inves de struct aluno)
*/
#include <string.h>
#include <stdio.h>

typedef struct aluno {
    int ra;
    char nome[100];
    char curso[20];
} aluno_t;

void print_aluno(aluno_t a) {
    printf("RA: %d\n", a.ra);
    printf("Nome: %s\n", a.nome);
    printf("Curso: %s\n", a.curso);
}

int main(int argc, char const *argv[])
{
    aluno_t a1;

    a1.ra = 123;
    strcpy(a1.nome, "Joao Silva");
    strcpy(a1.curso, "BCC");
    
    print_aluno(a1);

    aluno_t a2 = {
        .ra = 456,
        .nome = "Joana Siqueira",
        .curso = "BC&T"
    };

    print_aluno(a2);

    aluno_t a3;
    char temp;

    printf("RA: ");
    scanf("%d", &a3.ra);
    printf("Nome: ");
    fgets(a3.nome, 100, stdin);
    scanf("%[^\n]", a3.nome);
    scanf("%c", &temp);
    printf("Curso: ");
    scanf("%[^\n]", a3.curso);
    scanf("%c", &temp);

    print_aluno(a3);

    return 0;
}
