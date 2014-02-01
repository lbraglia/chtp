#include <stdio.h>

int main()
{
    int a, b, c, max, min;
    printf("Input three different integers: ");
    scanf("%d%d%d", &a, &b, &c);

    /* sum */
    printf("Sum is %d\n", a + b + c);

    /* average */
    printf("Average is %d\n", (a + b + c) / 3);

    /* product */
    printf("Product is %d\n", a * b * c);

    /* min */
    min = a;			/* let's assume a is min */
    if (b < min)
	min = b;
    if (c < min)
	min = c;
    printf("Smallest is %d\n", min);

    /* max */
    max = a;			/* let's assume a is min */
    if (b > max)
	max = b;
    if (c > max)
	max = c;
    printf("Largest is %d\n", max);

    return 0;
}
