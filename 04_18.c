#include <stdio.h>

int main()
{

    int a, b, c, d, e, index;

    printf("Enter five int beetween 1 and 30: ");

    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    printf("a: %d\t", a);
    for (index = 1; index <= a; index++)
	printf("*");
    printf("\n");

    printf("b: %d\t", b);
    for (index = 1; index <= b; index++)
	printf("*");
    printf("\n");

    printf("c: %d\t", c);
    for (index = 1; index <= c; index++)
	printf("*");
    printf("\n");

    printf("d: %d\t", d);
    for (index = 1; index <= d; index++)
	printf("*");
    printf("\n");

    printf("e: %d\t", e);
    for (index = 1; index <= e; index++)
	printf("*");
    printf("\n");


    return 0;
}
