#include <stdio.h>

int main()
{

    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number % 2 == 0)
	printf("number is even\n");
    if (number % 2 == 1)
	printf("number is odd\n");

    return 0;

}
