#include "queue.h"

#include <stdlib.h>

qu_queue_t* qu_create() {
    qu_queue_t* queue = malloc(sizeof(qu_queue_t));

    queue->list = create_list();

    return queue;
}   

void qu_destroy(qu_queue_t* queue) {
    destroy_list(queue->list);
    free(queue);
}

item_t qu_dequeue(qu_queue_t* queue) {
    return pop_front(queue->list);
}

void qu_enqueue(qu_queue_t* queue, item_t value) {
    push_back(queue->list, value);
}

item_t qu_first(qu_queue_t* queue) {
    return peek_front(queue->list);
}

item_t qu_last(qu_queue_t* queue) {
    return peek_back(queue->list);
}

int qu_size(qu_queue_t* queue) {
    return size(queue->list);
}

bool qu_is_empty(qu_queue_t* queue) {
    return list_is_empty(queue->list);
}

void qu_print(qu_queue_t* queue) {
    print_list(queue->list);
}