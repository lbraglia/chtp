#include <stdio.h>

int main()
{
    float gals, totgals = 0, miles, totmiles = 0;

    printf("Enter the gallons used (-1 to end): ");
    scanf("%f", &gals);

    while (gals == 0) {
	printf("Gallons can't be 0!\n");
	printf("Enter the gallons used (-1 to end): ");
	scanf("%f", &gals);
    }

    while (gals != -1) {

	printf("Enter the miles driven: ");
	scanf("%f", &miles);
	printf("The miles/gallons for this tank was %f\n\n", miles / gals);

	totgals += gals;
	totmiles += miles;

	printf("Enter the gallons used (-1 to end): ");
	scanf("%f", &gals);

	while (gals == 0) {
	    printf("Gallons can't be 0!\n");
	    printf("Enter the gallons used (-1 to end): ");
	    scanf("%f", &gals);
	}


    }

    printf("\nThe overall average miles/gallon was %f\n",
	   totmiles / totgals);

    return 0;
}
