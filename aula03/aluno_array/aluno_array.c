/**
 * Exemplos de array de struct.
*/

#include <string.h>
#include <stdio.h>

typedef struct aluno {
    int ra;
    char* nome;
    char* curso;
} aluno_t;

void print_aluno(aluno_t a) {
    printf("RA: %d\n", a.ra);
    printf("Nome: %s\n", a.nome);
    printf("Curso: %s\n", a.curso);
}

void print_alunos(aluno_t* alunos, int size) {
    for (int i = 0; i < size; i++) {
        printf("Aluno %d\n", i + 1);
        print_aluno(alunos[i]);
    }
}

int main(int argc, char const *argv[])
{
    aluno_t alunos[] = {
        {
            .ra = 123,
            .nome = "Joao Silva", 
            .curso = "BCC"
        },
        {
            .ra = 124,
            .nome = "Joana Siqueira", 
            .curso = "BC&T"
        },
        {
            .ra = 125,
            .nome = "Mario Moreira", 
            .curso = "BC&H"
        }
    };

    print_alunos(alunos, 3);

    return 0;
}
