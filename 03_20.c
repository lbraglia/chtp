#include <stdio.h>

int main()
{
    float principal;
    float rate;
    int days;
    float interest;

    printf("Enter loan principal (-1 to end): ");
    scanf("%f", &principal);

    while (principal != -1) {

	printf("Enter interest rate: ");
	scanf("%f", &rate);

	printf("Enter term of the loan in days: ");
	scanf("%d", &days);

	interest = principal * rate * days / 365;
	printf("The interest charge is $%.2f\n\n", interest);

	/* restart the cicle */
	printf("Enter loan principal (-1 to end): ");
	scanf("%f", &principal);

    }

    return 0;
}
