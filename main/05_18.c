#include <stdio.h>

int even(int number);

int main(void)
{
    int x;

    printf("Enter a integer: ");
    while (scanf("%d", &x) != EOF)
	printf("%d is %s\n", x, even(x) ? "even" : "odd");

    return 0;
}

int even(int number)
{
    return !(number % 2);
}
