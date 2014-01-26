#include <stdio.h>

int main()
{
    int counter = 1;

    while (counter <= 100) {
	printf("*");
	if (counter % 10 == 0)
	    printf("\n");
	counter++;
    }

    return 0;
}
