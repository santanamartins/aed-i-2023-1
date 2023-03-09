#include "queue.h"

#include <stdio.h>

int main(int argc, char const *argv[])
{
    qu_queue_t* queue = qu_create();

    for (int i = 0; i < 10; i++) {
        qu_enqueue(queue, i + 1);
        qu_print(queue);
    }
    for (int i = 0; i < 10; i++) {        
        printf("%d\n", qu_dequeue(queue));
        if (!qu_is_empty(queue)) {
            printf("%d\n", qu_first(queue));
            printf("%d\n", qu_last(queue));
        }
        qu_print(queue);
    }

    qu_destroy(queue);

    return 0;
}
