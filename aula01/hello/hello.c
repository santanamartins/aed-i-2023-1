/**
 * Hello World para testar se o ambiente de desenvolvimento esta funcionando.
*/
#include <stdio.h>

int main() {
    int a = 1;
    int b = 2;

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    int c = a;
    a = b;
    b = c;

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}