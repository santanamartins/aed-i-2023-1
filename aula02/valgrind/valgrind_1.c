/**
 * Programa simples para simular vazamento de memoria.
 * Para forcar um vazamento, comentar a linha free(n)
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int* n;
    
    n = malloc(sizeof(int));

    if (n == NULL) {
        fprintf(stderr, "Erro de alocacao\n");
        abort();
    }

    *n = 507;
    printf("%d\n", *n);
    free(n);

    return 0;
}
