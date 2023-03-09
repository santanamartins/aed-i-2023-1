#include "pilha.h"

#include <stdio.h>

void print_pilha(PilhaDinamica* pilha) {
    LinkedNode* cur = pilha->topo;

    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    PilhaDinamica* pilha = criar_pilha();

    for (int i = 0; i < 10; i++) {
        empilhar(pilha, i + 1);
        print_pilha(pilha);
    }    

    for (int i = 0; i < 10; i++) {
        int valor;
        desempilhar(pilha, &valor);
        printf("%d\n", valor);
        print_pilha(pilha);
    }

    liberar_pilha(pilha);

    return 0;
}
