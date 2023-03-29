#ifndef BST_NODE_H
#define BST_NODE_H

#include <stdbool.h>

typedef int item_t;

typedef struct bst_node_t {
    item_t value;
    struct bst_node_t* left;
    struct bst_node_t* right;
} bst_node_t;

void bst_destroy(bst_node_t* root);
bst_node_t* bst_insert(bst_node_t* root, item_t value);
bool bst_search(bst_node_t* root, item_t value);
void bst_print_inorder(bst_node_t* root);
void bst_print_preorder(bst_node_t* root);
void bst_print_postorder(bst_node_t* root);
bst_node_t* bst_find_min(bst_node_t* root);
bst_node_t* bst_remove(bst_node_t* root, item_t value, bool* removed);
int bst_height(bst_node_t* root);

#endif