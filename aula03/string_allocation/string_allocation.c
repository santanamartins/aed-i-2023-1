#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    // char array with immediate initialization
    char s1[] = "Hello World 1";

    puts(s1);

    // char array with delayed initialization
    char s2[100];

    strcpy(s2, "Hello World 2");

    puts(s2);

    // char array with scanf
    char s3[100];
    char temp;

    scanf("%[^\n]", s3);
    scanf("%c", &temp);

    puts(s3);

    // char ptr with immediate initialization
    char* s4 = "Hello World 4";

    puts(s4);

    // char ptr with late initialization
    char* s5 = malloc(sizeof(char) * 100);

    scanf("%[^\n]", s5);
    scanf("%c", &temp);

    puts(s5);
    free(s5);

    return 0;
}
