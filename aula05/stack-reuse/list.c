#include "list.h"

#include <stdlib.h>
#include <stdio.h>

/**
 * Construtor de lista.
*/
list_t* create_list() {
    list_t* list = malloc(sizeof(list_t));

    list->head = NULL;
    list->size = 0;

    return list;
}

/**
 * Destrutor de lista (iterativo).
 * 
 * @param list a lista
*/
void destroy_list(list_t* list) {
    node_t* cur = list->head;

    while (cur != NULL) {
        node_t* trash = cur;

        cur = cur->next;
        free(trash);
    }
    free(list);
}

/**
 * Destrutor de lista pura (recursivo).
 * 
 * @param node a cabeca da lista
*/
void destroy_recur_node(node_t* node) {
    if (node == NULL) {
        return;
    }
    destroy_recur_node(node->next);
    free(node);
}

/**
 * Destrutor de lista (recursivo).
 * 
 * @param list a lista
*/
void destroy_recur(list_t* list) {
    destroy_recur_node(list->head);
    free(list);
}

/**
 * Teste de lista vazia.
 * 
 * @param list a lista
*/
bool list_is_empty(list_t* list) {
    return list->head == NULL;
}

/**
 * Insercao na cabeca da lista.
 * 
 * @param list a lista
 * @param value o valor a inserir
*/
void push_front(list_t* list, item_t value) {
    node_t* node = malloc(sizeof(node_t));

    node->value = value;
    node->next = list->head;
    list->head = node;
    list->size++;
}

/**
 * Insercao no final da lista.
 * 
 * @param list a lista
 * @param value o valor a inserir
*/
void push_back(list_t* list, item_t value) {
    node_t* node = malloc(sizeof(node_t));

    node->value = value;
    node->next = NULL;

    node_t* cur = list->head;

    while (cur != NULL && cur->next != NULL) {
        cur = cur->next;
    }
    if (cur == NULL) { // empty list
        list->head = node;
    } else { // non-empty list
        cur->next = node;
    }
    list->size++;
}

/**
 * Consulta na cabeca da lista.
 * 
 * @param list a lista
 * @return o valor da cabeca
*/
item_t peek_front(list_t* list) {
    if (list_is_empty(list)) {
        fprintf(stderr, "Impossible to peek empty list");
        abort();
    }

    return list->head->value;
}

/**
 * Consulta no final da lista.
 * 
 * @param list a lista
 * @return o valor no final da lista
*/
item_t peek_back(list_t* list) {
    if (list_is_empty(list)) {
        fprintf(stderr, "Impossible to peek empty list");
        abort();
    }

    node_t* cur = list->head;

    while (cur->next != NULL) {
        cur = cur->next;
    }

    return cur->value;
}

/**
 * Remocao na cabeca da lista.
 * 
 * @param list a lista
 * @return o valor na cabeca da lista
*/
item_t pop_front(list_t* list) {
    if (list_is_empty(list)) {
        fprintf(stderr, "Impossible to remove from empty list");
    }

    node_t* trash = list->head;
    item_t value = trash->value;

    list->head = list->head->next;
    free(trash);
    list->size--;

    return value;
}

/**
 * Remocao no final da lista.
 * 
 * @param list a lista
 * @return o valor no final da lista
*/
item_t pop_back(list_t* list) {
    if (list_is_empty(list)) {
        fprintf(stderr, "Impossible to remove from empty list");
        abort();
    }

    node_t* prev = NULL;
    node_t* cur = list->head;

    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }

    item_t value = cur->value;

    if (cur == list->head) {
        list->head = NULL;
    } else {
        prev->next = NULL;
    }
    free(cur);
    list->size--;

    return value;
}

/**
 * Remocao via busca (em qualquer posicao).
 * 
 * @param list a lista
 * @param value a chave de busca
 * @return true se conseguiu encontrar e remover, false caso contrario
*/
bool list_remove(list_t* list, item_t value) {
    if (list_is_empty(list)) {
        return false;
    }

    node_t* prev = NULL;
    node_t* cur = list->head;

    while (cur != NULL && cur->value != value) {
        prev = cur;
        cur = cur->next;
    }

    if (cur != NULL) {
        node_t* trash = cur;

        if (cur == list->head) {
            list->head = list->head->next;
        } else {
            prev->next = cur->next;            
        }
        free(trash);
        list->size--;

        return true;
    }

    return false;
}

/**
 * Remocao via busca, em qualquer posicao (versao recursiva para lista pura).
 * 
 * @param value a chave de busca
 * @param node o no atual
 * @param size ponteiro para o tamanho atual da lista
 * @return a lista parcial
*/
node_t* list_remove_node_recur(item_t value, node_t* node, int* size) {
    if (node == NULL) {
        return NULL;
    }
    if (node->value == value) {
        node_t* next = node->next;

        free(node);
        (*size)--;

        return next;
    } 
    node->next = list_remove_node_recur(value, node->next, size);

    return node;
}

/**
 * Remocao via busca, em qualquer posicao (versao recursiva).
 * 
 * @param list a lista
 * @param value a chave de busca
*/
void list_remove_recur(list_t* list, item_t value) {
    list->head = list_remove_node_recur(value, list->head, &list->size);
}

/**
 * Consulta o tamanho da lista.
 * 
 * @param list a lista
 * @return o tamanho da lista
*/
int size(list_t* list) {
    return list->size;
}

/**
 * Imprime a lista com os elementos separados por espaco.
 * 
 * @param list a lista
*/
void print_list(list_t* list) {
    node_t* cur = list->head;

    while (cur != NULL) {
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}