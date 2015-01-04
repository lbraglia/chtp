/* 
   05_24.c fahrenheit to celsius; celsius to farhenheit
 */

#include <stdio.h>

double fahrenheit(double celsius);
double celsius(double fahrenheit);


int main(void)
{
    int index;

    printf("\nCelsius Fahrenheit  |  Fahrenheit Celsius\n");
    for (index = 0; index <= (212 - 32); index++) {
	if (index <= 100) {
	    /* celsius to fahrenheit */
	    printf("%7d %10.2f", index, fahrenheit(index));
	    /* separator */
	    printf("  |  ");
	} else {
	    /* blank for Celsius to fahrenheit */
	    printf("                    |  ");
	}

	/* fahrenheit to celsius */
	printf("%10d %7.2f\n", index + 32, celsius(index + 32));

    }
    printf("\n");


    return 0;

}


double celsius(double fahrenheit)
{
    return ((5.0 / 9.0) * (fahrenheit - 32.0));

}

double fahrenheit(double celsius)
{
    return ((9.0 / 5.0) * celsius + 32);

}
