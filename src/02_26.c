#include <stdio.h>

int main()
{

    int a, b;

    printf("Enter two integers, first a then b: ");
    scanf("%d %d", &a, &b);

    if (a % b == 0)
	printf("a is a multiple of b\n");
    else
	printf("a is not a multiple of b\n");

    return 0;

}
