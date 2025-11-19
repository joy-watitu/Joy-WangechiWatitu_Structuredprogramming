#include <stdio.h>

int main() {
    int a, b;

    printf("Enter first number: ");
    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    printf("\n--- Results ---\n");
    printf("Addition: %d\n", a + b);
    printf("Subtaction: %d\n", a - b);
    printf("Multiplication: %d\n", a * b);
    printf("Division: %.2f\n", (float)a / b);
    printf("Modulus: %d\n", a % b);

    return 0;
}
