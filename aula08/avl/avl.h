#ifndef AVL_H
#define AVL_H

#include <stdbool.h>

typedef int item_t;

typedef struct avl_node_t {
    item_t value;
    struct avl_node_t* left;
    struct avl_node_t* right;
    int height;
} avl_node_t;

void avl_destroy(avl_node_t* root);
avl_node_t* avl_insert(avl_node_t* root, item_t value);
avl_node_t* avl_remove(avl_node_t* root, item_t value, bool* removed);
void avl_print(avl_node_t* root);

#endif