#include <stdio.h>

int main()
{

    int a, b;

    printf("Enter two integer:\n");
    scanf("%d %d", &a, &b);

    if (a > b)
	printf("%d is larger\n", a);
    if (b > a)
	printf("%d is larger\n", b);
    if (b == a)
	printf("These numbers are equal\n");

    return 0;

}
