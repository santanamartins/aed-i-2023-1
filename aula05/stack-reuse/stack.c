#include "stack.h"

#include <stdlib.h>

stk_stack_t* stk_create() {
    stk_stack_t* stack = malloc(sizeof(stk_stack_t));

    stack->list = create_list();

    return stack;
}

void stk_destroy(stk_stack_t* stack) {
    destroy_list(stack->list);
    free(stack);
}

bool stk_is_empty(stk_stack_t* stack) {
    return list_is_empty(stack->list);
}

void stk_push(stk_stack_t* stack, item_t value) {
    push_front(stack->list, value);
}

item_t stk_pop(stk_stack_t* stack) {
    return pop_front(stack->list);
}

item_t stk_top(stk_stack_t* stack) {
    return peek_front(stack->list);
}

int stk_size(stk_stack_t* stack) {
    return size(stack->list);
}

void stk_print(stk_stack_t* stack) {
    print_list(stack->list);
}