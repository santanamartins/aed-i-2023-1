#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef int item_t;

/**
 * No de lista.
*/
typedef struct node_t {
    item_t value;
    struct node_t* next;
} node_t;

/**
 * Tipo abstrato que agrega a cabeca da 
 * lista e um contador de elementos.
*/
typedef struct list_t {
    node_t* head;
    int size;
} list_t;

list_t* create_list();
bool list_is_empty(list_t* list);
void push_front(list_t* list, item_t value);
void push_back(list_t* list, item_t value);
item_t peek_front(list_t* list);
item_t peek_back(list_t* list);
item_t pop_front(list_t* list);
item_t pop_back(list_t* list);
int size(list_t* list);
void print_list(list_t* list);
void destroy_list(list_t* list);
void destroy_recur(list_t* list);
bool list_remove(list_t* list, item_t value);
void list_remove_recur(list_t* list, item_t value);


#endif