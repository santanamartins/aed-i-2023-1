#include "fila.h"

#include <stdlib.h>

FilaDinamica *criar_fila() {
    FilaDinamica* fila = malloc(sizeof(FilaDinamica));

    fila->inicio = NULL;
    fila->fim = NULL;

    return fila;
}

int enfileirar(FilaDinamica *fila, int valor) {
    LinkedNode* node = malloc(sizeof(LinkedNode));

    if (node == NULL) {
        return 0;
    }

    node->data = valor;
    node->next = NULL;

    if (fila->inicio == NULL) { // vazia
        fila->inicio = node;
    } else { // nao vazia
        fila->fim->next = node;
        
    }
    fila->fim = node;

    return 1;
}

int desenfileirar(FilaDinamica *fila, int *valor) {
    if (fila->inicio == NULL) {
        return 0;
    }
    *valor = fila->inicio->data;

    LinkedNode* trash = fila->inicio;

    fila->inicio = fila->inicio->next;
    free(trash);
    
    return 1;
}

void liberar_fila(FilaDinamica *fila) {
    LinkedNode* cur = fila->inicio;

    while (cur != NULL) {
        LinkedNode* trash = cur;

        cur = cur->next;
        free(trash);
    }
    free(fila);
}