#include <stdio.h>

int main()
{
    int number, nofint, total = 0, counter = 1;

    printf("Please insert # of integer to be summed: ");
    scanf("%d", &nofint);

    for (counter = 1; counter <= nofint; counter++) {
	printf("Enter integer # %d: ", counter);
	scanf("%d", &number);
	total += number;
    }

    printf("Sum of integer entered is %d\n", total);

    return 0;

}
