
/**
 * Outra forma de "retornar" um array a partir de uma funcao eh, ao inves de
 * usar um valor de retorno, utilizar um parametro por referencia.
 * Passamos o vetor como argumento de cria_vetor_aleatorio e fazemos apenas
 * o povoamento dos valores dentro da funcao. A alocacao e a desalocacao ficam
 * a cargo da main (o que inclusive eh vantajoso, pois o gerenciamento 
 * da memoria nao fica "espalhado" no programa).
 * Nesse caso seria possivel tambem trabalhar com vetor alocado estaticamente.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cria_vetor_aleatorio(int* vetor, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        vetor[i] = rand();
    }
}

void imprime_vetor(int* v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int* v = calloc(10, sizeof(int));

    cria_vetor_aleatorio(v, 10);

    imprime_vetor(v, 10);

    free(v);

    return 0;
}

