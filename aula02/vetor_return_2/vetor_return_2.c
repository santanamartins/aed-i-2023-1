/**
 * Demonstra como retornar um vetor a partir de uma funcao utilizando
 * alocacao dinamica.
 * */

#include <stdio.h>
#include <stdlib.h>

int* cria_vetor_aleatorio(int n) {
    int* vetor = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        vetor[i] = rand();
    }

    return vetor;
}

void imprime_vetor(int* v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int* v = cria_vetor_aleatorio(10);

    imprime_vetor(v, 10);

    free(v);

    return 0;
}
