#include "disciplina.h"

#include <stdio.h>
#include <stdlib.h>

void ident(int ident_size) {
    for (int i = 0; i < ident_size; i++) {
        printf(" ");
    }
}

/**
 * Imprime uma disciplina, aplicando indentacao programaticamente.
*/
void print_disciplina_w_indent(disciplina_t* d, int indent_size) {
    ident(indent_size);
    printf("Codigo: %d\n", d->cod);
    ident(indent_size);
    printf("Nome: %s\n", d->nome);
    ident(indent_size);
    printf("Creditos: %d\n", d->creditos);
    ident(indent_size);
    if (d->recomendacao != NULL) {
        printf("Recomendacao: \n");
        print_disciplina_w_indent(d->recomendacao, indent_size + 4);
    }
    printf("\n");
}

void print_disciplina(disciplina_t* d) {
    print_disciplina_w_indent(d, 0);
}

/**
 * Construtor de disciplina (alocacao estatica).
*/
disciplina_t cria_disciplina(int cod, char* nome, int creditos, disciplina_t* recomendacao) {
    disciplina_t d = {
        .cod = cod,
        .nome = nome,
        .creditos = creditos,
        .recomendacao = recomendacao
    };

    return d;
}

/**
 * Construtor de disciplina (alocacao dinamica).
*/
disciplina_t* cria_disciplina_ptr(int cod, char* nome, int creditos, disciplina_t* recomendacao) {
    disciplina_t* d = malloc(sizeof(disciplina_t));

    d->cod = cod;
    d->nome = nome;
    d->creditos = creditos;
    d->recomendacao = recomendacao;

    return d;
}