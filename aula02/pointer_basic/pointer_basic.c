/**
 * Testes de uso de ponteiros. Codigos que geram erros de compilacao
 * estao comentados.
*/

#include <stdio.h>

int main(int argc, char const *argv[]) {
    int x = 10;
    int* y = &x;
    
    printf("%d\n", x);
    printf("%p\n", y);
    printf("%d\n", *y);
    printf("\n");


    // int* y = 20;
    // printf("%p\n", y);

    int* z = y;

    printf("%d\n", x);
    printf("%p\n", y);
    printf("%d\n", *y);
    printf("%p\n", z);
    printf("%d\n", *z);
    printf("\n");

    *z = 20;

    printf("%d\n", x);
    printf("%p\n", y);
    printf("%d\n", *y);
    printf("%p\n", z);
    printf("%d\n", *z);
    printf("\n");

    return 0;
}
