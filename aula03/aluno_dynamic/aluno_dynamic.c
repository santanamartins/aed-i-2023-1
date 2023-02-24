/**
 * Alocacao dinamica de struct (vide funcao create_aluno)
*/
#include "aluno.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

aluno_t* create_aluno() {
    aluno_t* a1 = malloc(sizeof(aluno_t));

    a1->ra = 123;
    a1->nome = "Mario Moreira";
    a1->curso = "BCC";

    return a1;
}

int main(int argc, char const *argv[])
{   
    aluno_t* a1 = create_aluno();
    print_aluno(a1);

    free(a1);
    /* code */
    return 0;
}
