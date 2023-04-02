#include "avl.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int maximum(int a, int b) {
    if (a > b) {
        return a;
    }

    return b;
}

int avl_height(avl_node_t* root) {
    if (root == NULL) {
        return 0;
    }
    
    return root->height;
}

void avl_destroy(avl_node_t* root) {
    if (root != NULL) {
        avl_destroy(root->left);
        avl_destroy(root->right);
        free(root);
    }
}

avl_node_t* avl_create_node(item_t value) {
    avl_node_t* node = malloc(sizeof(avl_node_t));

    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

/**
 * The bf factor: 
 * - is positive if the tree is unbalanced to the left 
 * - is negative if the tree is unbalanced to the right
*/
int avl_balance_factor(avl_node_t* root) {
    if (root == NULL) {
        return 0;
    }
    
    return avl_height(root->left) - avl_height(root->right);
}

void update_height(avl_node_t* root) {
    if (root != NULL) {
        root->height = 1 + maximum(avl_height(root->left), avl_height(root->right));
    }
}

avl_node_t* avl_rotate_left(avl_node_t* root) {
    avl_node_t* pivot = root->right;

    root->right = pivot->left;
    pivot->left = root;

    update_height(root);
    update_height(pivot);

    return pivot;
}

avl_node_t* avl_rotate_right(avl_node_t* root) {
    avl_node_t* pivot = root->left;

    root->left = pivot->right;
    pivot->right = root;

    update_height(root);
    update_height(pivot);

    return pivot;
}

avl_node_t* avl_rebalance(avl_node_t* root) {
    if (root == NULL) {
        return root;
    }

    int bf = avl_balance_factor(root);
    int bf_r = avl_balance_factor(root->right);
    int bf_l = avl_balance_factor(root->left);

    if (bf >= -1 && bf <= 1) {
        return root;
    } else if (bf < -1 && bf_r <= 0) { // L
        root = avl_rotate_left(root);
    } else if (bf > 1 && bf_l >= 0) { // R
        root = avl_rotate_right(root);
    } else if (bf < -1 && bf_r > 0) { // RL
        root->right = avl_rotate_right(root->right);
        root = avl_rotate_left(root);
    } else if (bf > 1 && bf_l < 0) { // LR
        root->left = avl_rotate_left(root->left);
        root = avl_rotate_right(root);
    }

    return root;
}

avl_node_t* avl_insert(avl_node_t* root, item_t value) {
    if (root == NULL) {
        return avl_create_node(value);
    }
    if (value < root->value) {
        root->left = avl_insert(root->left, value);
    }
    if (value > root->value) {
        root->right = avl_insert(root->right, value);
    }
    update_height(root);

    return avl_rebalance(root);
}

avl_node_t* avl_find_min(avl_node_t* root) {
    if (root->left == NULL) {
        return root;
    }

    return avl_find_min(root->left);
}


avl_node_t* avl_remove(avl_node_t* root, item_t value, bool* removed) {
    if (root == NULL) {
        return NULL;
    }
    if (value < root->value) {
        root->left = avl_remove(root->left, value, removed);
    } else if (value > root->value) {
        root->right = avl_remove(root->right, value, removed);
    } else {
        if (root->right == NULL) {
            avl_node_t* child = root->left;

            free(root);
            *removed = true;

            return child;
        }
        if (root->left == NULL) {
            avl_node_t* child = root->right;

            free(root);
            *removed = true;

            return child;
        }
        avl_node_t* min_child = avl_find_min(root->right);

        root->value = min_child->value;
        root->right = avl_remove(root->right, min_child->value, removed);
    }

    update_height(root);

    return avl_rebalance(root);
}

void fill_spaces(int size) {
    for (int i = 0; i < size; i++) {
        printf(" ");
    }
}

void print_with_indent(avl_node_t* root, int indent) {
    if (root != NULL) {
        printf("\n");
        fill_spaces(indent);
        printf("(");
        printf("%d,%d", root->value, avl_height(root));
        print_with_indent(root->right, indent + 2);
        print_with_indent(root->left, indent + 2);
        printf(")");
    } else {
        printf("\n");
        fill_spaces(indent);
        printf("()");
    }
}

void avl_print(avl_node_t* root) {
    print_with_indent(root, 0);
}