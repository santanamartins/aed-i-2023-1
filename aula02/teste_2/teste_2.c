/**
 * Teste de dereferencia de ponteiros e mutacao.
*/

#include <stdio.h>

int main(int argc, char const *argv[]) {
    int x = 10;
    int* y = &x;
    int* z = &x;
    int c = *y + *z;

    *y = c;

    printf("%d\n", x);

    return 0;
}
