#include <stdio.h>

int main() {
    int n, i, j;
    int arr[100];
    int isUnique;

    printf("Input the number of elements to be stored in the array : ");
    scanf("%d", &n);

    printf("Input %d elements in the array :\n", n);
    for (i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("The unique elements found in the array are : ");
    for (i = 0; i < n; i++) {
        isUnique = 1;
        for (j = 0; j < n; j++)
            {
            if (i != j && arr[i] == arr[j])
                  {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            printf("%d ", arr[i]);
        }
    }

  return 0;
}
