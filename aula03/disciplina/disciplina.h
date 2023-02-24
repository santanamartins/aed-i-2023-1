#ifndef DISCIPLINA_H
#define DISCIPLINA_H

typedef struct disciplina {
    int cod;
    char* nome;
    int creditos;
    struct disciplina* recomendacao;
} disciplina_t;

void print_disciplina(disciplina_t* d);
disciplina_t cria_disciplina(int cod, char* nome, int creditos, disciplina_t* recomendacao);
disciplina_t* cria_disciplina_ptr(int cod, char* nome, int creditos, disciplina_t* recomendacao);
#endif