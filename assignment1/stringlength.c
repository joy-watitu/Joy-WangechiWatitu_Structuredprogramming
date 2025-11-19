#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    int length;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Hello, %s!\n", name);

    length = strlen(name);
    printf("Your name has %d letters.\n", length);

    return 0;
}
