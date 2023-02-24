
/**
 * Programa com erro de logica no gerenciamento de memoria (gera segmentation fault).
 * A funcao cria_vetor_aleatorio retorno um ponteiro para variavel local, a qual eh
 * desalocada ao termino da funcao, consequemente o ponteiro v em main fica nulo.
*/
#include <stdio.h>
#include <stdlib.h>

int* cria_vetor_aleatorio(int n) {
    int vetor[n];

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

    return 0;
}
