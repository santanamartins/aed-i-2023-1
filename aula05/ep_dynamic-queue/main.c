#include "fila.h"

#include <stdio.h>

void print_fila(FilaDinamica* fila) {
    LinkedNode* cur = fila->inicio;

    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    FilaDinamica* fila = criar_fila();

    for (int i = 0; i < 10; i++) {
        enfileirar(fila, i + 1);
        print_fila(fila);
    }
    for (int i = 0; i < 10; i++) {
        int valor;
        desenfileirar(fila, &valor);
        printf("%d\n", valor);
        print_fila(fila);
    }

    liberar_fila(fila);

    return 0;
}
