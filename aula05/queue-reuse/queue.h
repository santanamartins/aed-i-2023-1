#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#include "list.h"

typedef struct qu_queue_t {
    list_t* list;
} qu_queue_t;

qu_queue_t* qu_create();
void qu_destroy(qu_queue_t*);
item_t qu_dequeue(qu_queue_t*);
void qu_enqueue(qu_queue_t*, item_t);
item_t qu_first(qu_queue_t*);
item_t qu_last(qu_queue_t*);
int qu_size(qu_queue_t*);
bool qu_is_empty(qu_queue_t*);
void qu_print(qu_queue_t*);

#endif