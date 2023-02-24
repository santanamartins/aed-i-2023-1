/**
 * Demonstra mutacao de ponteiro dereferenciado.
*/
#include <stdio.h>

int main(int argc, char const *argv[]) {
    
    int x = 2;
    int *y = &x;

    *y = 3;
    
    printf("%d\n", x);
    
    return 0;
}
