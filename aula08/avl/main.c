#include "avl.h"

#include <stdio.h>
#include <stdlib.h>

int compare_int(const void* a, const void* b) {
    int a_i = *(const int*)a;
    int b_i = *(const int*)b;

    if (a_i < b_i) {
        return -1;
    } else if (a_i > b_i) {
        return -1;
    }

    return 0;
}

int main(int argc, char const *argv[]) {
    avl_node_t* root = NULL;
    // item_t values[] = {5, 3, 8, 1, 4, 7};
    item_t values[] = {5, 6, 8, 3, 2, 4, 7};
    // item_t values[] = {1, 2, 3, 4, 5, 6, 7};

    for (int i = 0; i < 7; i++) {
        printf("Insert: %d\n", values[i]);
        root = avl_insert(root, values[i]);
        avl_print(root);
        printf("\n");
    }    

    qsort(values, 7, sizeof(int), compare_int);
    for (int i = 0; i < 7; i++) {
        bool removed = false;

        printf("Remove: %d\n", values[i]);
        root = avl_remove(root, values[i], &removed);
        avl_print(root);
        printf("\n");
    }
    
    avl_destroy(root);

    return 0;
}
