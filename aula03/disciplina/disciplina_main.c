/**
 * Demonstra o encadeamento, ou aninhamento recursivo, de structs.
 * No arquivo disciplina.h, temos uma struct disciplina que possui um componente
 * do proprio tipo disciplina (aninhamento recursivo). Dessa forma, podemos
 * encadear structs do mesmo tipo de acordo com alguma semantica (nesse caso, 
 * o encadeamento se da pelos requisitos da disciplina).
*/

#include "disciplina.h"

#include <stdlib.h>

int main(int argc, char const *argv[])
{   
    disciplina_t pe;
    disciplina_t aed;

    pe.cod = 0;
    pe.nome = "Programacao Estruturada";
    pe.creditos = 4;
    pe.recomendacao = NULL;

    aed.cod = 1;
    aed.nome = "Algoritmos e Estruturas de Dados I";
    aed.creditos = 4;
    aed.recomendacao = &pe;

    print_disciplina(&aed);

    disciplina_t bcc = cria_disciplina(124, "Bases Computacionais da Ciencia", 4, NULL);
    disciplina_t pi = cria_disciplina(125, "Processamento da Informacao", 6, &bcc);

    print_disciplina(&bcc);
    print_disciplina(&pi);

    disciplina_t* bcc1 = cria_disciplina_ptr(124, "Bases Computacionais da Ciencia", 4, NULL);
    disciplina_t* pi1 = cria_disciplina_ptr(125, "Processamento da Informacao", 6, bcc1);

    print_disciplina(bcc1);
    print_disciplina(pi1);

    free(bcc1);
    free(pi1);

    return 0;
}
