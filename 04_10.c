#include <stdio.h>

int main()
{
    int number, counter = 0, sumofint = 0;

    while (1) {

	printf("Enter int to be summed (9999 to exit): ");
	scanf("%d", &number);
	if (number == 9999)
	    break;
	sumofint += number;
	counter++;

    }

    if (counter != 0)
	printf("Mean is %f\n", (float) sumofint / counter);

}
