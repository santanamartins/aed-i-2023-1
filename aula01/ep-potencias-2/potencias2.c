/**
 * Solucao para o EP potencias de 2.
*/
#include <stdio.h>

int main() {
    int n;
    int c = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k;
        int p = 1;
        scanf("%d", &k);
        
        while (p < k) {
            p *= 2;
        }
        if (k == p) {
            c++;
        }
    }
    printf("%d\n", c);

    return 0;
}