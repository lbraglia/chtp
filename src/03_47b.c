/* 
   03_47: slightly modified e approximation
 */


#include <stdio.h>

int main(void)
{

    float e = 2.7182817459;
    float approx = 0.0;
    float precision;
    int denominator_factorial = 1;
    /* counter of the addend */
    int counter = 0;
    int counter_backup;

    printf("Insert desired precision ([0,1] interval, thanks..): ");
    scanf("%f", &precision);

    while (e - approx > precision) {

	counter_backup = counter;

	/* Calculating factorial */
	while (counter >= 0) {
	    denominator_factorial = (counter > 0 ?
				     denominator_factorial * counter :
				     denominator_factorial * 1);
	    counter--;
	}

	approx = approx + (float) 1 / denominator_factorial;
	denominator_factorial = 1;
	counter = counter_backup + 1;

    }

    printf("e=\t%.10f\n", e);
    printf("approx=\t%.10f\n", approx);
    printf("diff=\t%.10f\n", e - approx);

    return 0;
}
