#include "list.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
    list_t* list = create_list();

    push_front(list, 10);
    push_front(list, 20);
    push_front(list, 30);
    print_list(list);
    push_back(list, 40);
    push_back(list, 50);
    print_list(list);

    printf("%d\n", pop_back(list));
    printf("%d\n", pop_back(list));
    print_list(list);

    printf("%d\n", pop_front(list));
    printf("%d\n", pop_front(list));
    print_list(list);

    printf("%d\n", peek_back(list));
    print_list(list);

    list_remove(list, 10);
    print_list(list);
    printf("%d\n", size(list));
    print_list(list);

    destroy_list(list);
    // destroy_recur(list);

    return 0;
}
