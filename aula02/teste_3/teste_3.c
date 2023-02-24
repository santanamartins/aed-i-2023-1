/**
 * Teste de mutacao de ponteiros.
*/
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int x = 8;

    x++;

    int* y = &x;
    *y = *y + 1;

    printf("%d\n", x);

    return 0;
}
