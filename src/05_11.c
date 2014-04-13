#include <stdio.h>
#include <math.h>

/* gcc -lm 05_11.c */

double roundToInteger(double number);
double roundToTenths(double number);
double roundToHundreths(double number);
double roundToThousandths(double number);

int main(void)
{

    double x;

    printf("Enter a number: ");

    while (scanf("%lf", &x) != EOF) {
	printf("\n");
	printf("x = %f\n", x);
	printf("roundToInteger(x) = %f\n", roundToInteger(x));
	printf("roundToTenths(x) = %f\n", roundToTenths(x));
	printf("roundToHundreths(x) = %f\n", roundToHundreths(x));
	printf("roundToThousandths(x) = %f\n", roundToThousandths(x));
	printf("\n");
	printf("Enter a number: ");
    }

    return 0;

}

double roundToInteger(double number)
{
    return floor(number + .5);
}

double roundToTenths(double number)
{
    return floor(number * 10 + .5) / 10;
}

double roundToHundreths(double number)
{
    return floor(number * 100 + .5) / 100;
}

double roundToThousandths(double number)
{
    return floor(number * 1000 + .5) / 1000;
}
