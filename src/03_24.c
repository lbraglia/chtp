#include <stdio.h>

int main()
{

    int counter = 1, largest_ID;
    float number, largest = 0.0;

    while (counter <= 10) {
	printf("Insert # %d: ", counter);
	scanf("%f", &number);
	if (number > largest) {
	    largest = number;
	    largest_ID = counter;
	}

	counter++;

    }

    printf("Largest is # %d: %f\n", largest_ID, largest);
    return 0;

}
