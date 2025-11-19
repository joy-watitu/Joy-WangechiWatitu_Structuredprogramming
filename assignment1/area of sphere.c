#include <stdio.h>
#include <math.h>


int main() {
    float radius, area;
    const float PI = 3.1416;

    printf("Enter the radius of the sphere: ");
    scanf("%f", &radius);

    area = 4 * PI * radius *radius;

    printf("Surface area of the sphere: %.2f\n", area);

    return 0;
}
