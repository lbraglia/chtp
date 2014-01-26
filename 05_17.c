#include <stdio.h>

int multiple(int first, int second);

int main(void)
{

    int a, b;

    printf("Enter two integers: ");
    scanf("%d%d", &a, &b);

    if (multiple(a, b))
	printf("Second number is a multiple of the first one\n");
    else
	printf("Second number is NOT a multiple of the first one\n");


    return 0;
}

int multiple(int first, int second)
{
    return !(first % second);
}
