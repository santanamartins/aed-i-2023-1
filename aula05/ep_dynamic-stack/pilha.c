#include "pilha.h"

#include <stdlib.h>

PilhaDinamica* criar_pilha() {
    PilhaDinamica* pilha = malloc(sizeof(PilhaDinamica));

    pilha->topo = NULL;

    return pilha;
}

int empilhar(PilhaDinamica* pilha, int valor) {
    LinkedNode* node = malloc(sizeof(LinkedNode));

    if (node == NULL) {
        return 0;
    }

    node->data = valor;
    node->next = pilha->topo;
    pilha->topo = node;

    return 1;
}


int desempilhar(PilhaDinamica* pilha, int* valor) {
    if (pilha->topo == NULL) {
        return 0;
    }
    *valor = pilha->topo->data;

    LinkedNode* trash = pilha->topo;

    pilha->topo = pilha->topo->next;
    free(trash);

    return 1;
}

void liberar_pilha(PilhaDinamica *pilha) {
    LinkedNode* cur = pilha->topo;

    while (cur != NULL) {
        LinkedNode* trash = cur;

        cur = cur->next;
        free(trash);
    }
    free(pilha);
}