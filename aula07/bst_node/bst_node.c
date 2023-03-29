#include "bst_node.h"

#include <stdlib.h>
#include <stdio.h>

item_t max_item(item_t a, item_t b) {
    if (a >= b) {
        return a;
    }

    return b;
}

bst_node_t* bst_create(item_t value) {
    bst_node_t* node = malloc(sizeof(bst_node_t));

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void bst_destroy(bst_node_t* root) {
    if (root != NULL) {
        bst_destroy(root->left);
        bst_destroy(root->right);
        free(root);
    }
}

bst_node_t* bst_insert(bst_node_t* root, item_t value) {
    if (root == NULL) {
        return bst_create(value);
    } else if (value < root->value) {
        root->left = bst_insert(root->left, value);
    } else if (value > root->value) {
        root->right = bst_insert(root->right, value);
    }

    return root;
}

bool bst_search(bst_node_t* root, item_t value) {
    if (root != NULL) {
        if (value < root->value) {
            return bst_search(root->left, value);
        } else if (value > root->value) {
            return bst_search(root->right, value);
        }

        return true;
    }

    return false;
}

void bst_print_inorder(bst_node_t* root) {
    if (root != NULL) {
        bst_print_inorder(root->left);
        printf("%d ", root->value);
        bst_print_inorder(root->right);
    }
}

void bst_print_preorder(bst_node_t* root) {
    if (root != NULL) {
        printf("(");
        printf("%d", root->value);
        bst_print_preorder(root->left);
        bst_print_preorder(root->right);
        printf(")");
    } else {
        printf("()");
    }
}

void bst_print_postorder(bst_node_t* root) {
    if (root != NULL) {
        bst_print_postorder(root->left);
        bst_print_postorder(root->right);
        printf("%d ", root->value);
    }
}

bst_node_t* bst_find_min(bst_node_t* root) {
    if (root->left == NULL) {
        return root;
    }

    return bst_find_min(root->left);
}

bst_node_t* bst_remove(bst_node_t* root, item_t value, bool* removed) {
    if (root == NULL) {
        return NULL;
    }
    if (value < root->value) {
        root->left = bst_remove(root->left, value, removed);
    } else if (value > root->value) {
        root->right = bst_remove(root->right, value, removed);
    } else {
        if (root->right == NULL) {
            bst_node_t* child = root->left;

            free(root);
            *removed = true;

            return child;
        }
        if (root->left == NULL) {
            bst_node_t* child = root->right;

            free(root);
            *removed = true;

            return child;
        }
        bst_node_t* min_child = bst_find_min(root->right);

        root->value = min_child->value;
        root->right = bst_remove(root->right, min_child->value, removed);
    }

    return root;
}

int bst_height(bst_node_t* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + max_item(bst_height(root->left), bst_height(root->right));
    }
}