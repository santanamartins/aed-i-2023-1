#ifndef STACK_H
#define STACK_H

#include "list.h"
#include <stdbool.h>

typedef struct stk_stack_t {
    list_t* list;
} stk_stack_t;

stk_stack_t* stk_create();
void stk_destroy(stk_stack_t*);
bool stk_is_empty(stk_stack_t*);
void stk_push(stk_stack_t*, item_t);
item_t stk_pop(stk_stack_t*);
item_t stk_top(stk_stack_t*);
int stk_size(stk_stack_t*);
void stk_print(stk_stack_t*);

#endif