#include <stdio.h>

#define ROWS 6
#define COLS 4

int main() {
    // Step 1: Declare and initialize the 2D array
    int arr[ROWS][COLS] = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}
    };

    // Step 2: Traverse and print each element
    printf("2D Array Traversal:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }

    return 0;
}
