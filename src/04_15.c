#include <stdio.h>
#include <math.h>
int main(void)
{
    double amount;
    double principal = 1000.0;
    double rate;
    int year;
    for (rate = .05; rate <= 0.1; rate += 0.01) {
	printf("Rate: %.2f\n\n", rate);
	printf("%6s%21s\n", "Year", "Amount on deposit");
	for (year = 1; year <= 10; year++) {
	    amount = principal * pow(1.0 + rate, year);
	    printf("%6d%21.2f\n", year, amount);
	}
	printf("\n");
    }
    return 0;
}
