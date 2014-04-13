#include <stdio.h>
#include <math.h>

/* to be compiled with "gcc -lm 05_10.c" */

double myround(double number);

int main(void)
{
    double x;

    printf("Enter a number: ");
    while (scanf("%lf", &x) != EOF) {	/* %lf --> double */
	printf("myround(%.3f) = %.3f\n", x, myround(x));
	printf("Enter a number: ");
    }

    return 0;

}

double myround(double number)
{
    return floor(number + .5);
}
