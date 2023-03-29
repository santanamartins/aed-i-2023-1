#include "bst_node.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int values[] = {5, 3, 8, 1, 4, 7};

    bst_node_t* root = NULL;

    for (int i = 0; i < 6; i++) {
        root = bst_insert(root, values[i]);
    }
    bst_print_inorder(root);
    printf("\n");
    bst_print_preorder(root);
    printf("\n");
    bst_print_postorder(root);
    printf("\n");

    for (int i = 0; i < 6; i++) {
        printf("%s ", (bst_search(root, values[i]) ? "true" : "false"));
    }
    printf("\n");
    printf("%s\n", (bst_search(root, 5) ? "true" : "false"));

    bool removed = false;

    printf("%d\n", bst_height(root));

    root = bst_remove(root, 3, &removed);
    bst_print_preorder(root);
    printf("%s\n", removed ? "true" : "false");
    removed = false;
    root = bst_remove(root, 5, &removed);
    bst_print_preorder(root);
    printf("%s\n", removed ? "true" : "false");
    removed = false;

    printf("%d\n", bst_height(root));
    root = bst_remove(root, 1, &removed);
    printf("%d\n", bst_height(root));

    bst_destroy(root);
    
    return 0;
}
