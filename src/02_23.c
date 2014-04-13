#include <stdio.h>

int main()
{
    int a, b, c, d, e, max, min;

    printf("Enter 5 different integers: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    /* min */
    min = a;
    if (b < min)
	min = b;
    if (c < min)
	min = c;
    if (d < min)
	min = d;
    if (e < min)
	min = e;
    printf("min is %d\n", min);

    max = a;
    if (b > max)
	max = b;
    if (c > max)
	max = c;
    if (d > max)
	max = d;
    if (e > max)
	max = e;
    printf("max is %d\n", max);

    return 0;
}
