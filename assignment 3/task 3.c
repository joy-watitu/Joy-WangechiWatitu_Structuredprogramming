#include <stdio.h>


int main()
{
    int count = 10;
    int *pCount = &count;

    // modify using pointer
    *pCount = 20;
    printf("The updated value of count: %d\n", count);

    return 0;
}
