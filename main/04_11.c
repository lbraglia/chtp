#include <stdio.h>

int main()
{
    int number, nofint, counter, min = 9999;

    printf("Enter # of int to be inserted: ");
    scanf("%d", &nofint);

    for (counter = 1; counter <= nofint; counter++) {
	printf("Enter # %d: ", counter);
	scanf("%d", &number);
	if (number < min)
	    min = number;
    }

    printf("min is %d\n", min);

}
