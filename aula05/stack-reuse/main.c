#include "stack.h"

#include <stdio.h>

int main(int argc, char const *argv[]) {
    stk_stack_t* stack = stk_create();

    for (int i = 0; i < 10; i++) {
        stk_push(stack, i + 1);
        stk_print(stack);
    }    

    for (int i = 0; i < 10; i++) {
        printf("%d\n", stk_pop(stack));
        if (!stk_is_empty(stack)) {
            printf("%d\n", stk_top(stack));
        }
        stk_print(stack);
    }

    stk_destroy(stack);

    return 0;
}
