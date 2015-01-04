/* 
   02_20.c: diameter, circumference and area of a circle given radius

 */

#include <stdio.h>

int main(void)
{
    int radius;

    printf("Insert radius of the circle: ");
    scanf("%d", &radius);

    printf("Radius: %f\n", radius * 1.0);
    printf("Diameter: %f\n", radius * 2.0);
    printf("Circumference: %f\n", radius * 2 * 3.1415);
    printf("Area: %f\n", radius * radius * 3.1415);

    return 0;
}
