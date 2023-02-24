#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno {
    int ra;
    char* nome;
    char* curso;
} aluno_t;

void print_aluno(aluno_t* a);
void print_alunos(aluno_t* alunos, int size);

#endif