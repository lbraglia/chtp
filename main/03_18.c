#include <stdio.h>

int main(void)
{
    int accnum;			/* account number */
    float begbal;		/* beginning balance */
    float totcharges;		/* total charges */
    float totcreds;		/* total credits */
    float credlim;		/* credit limit */
    float newbal;		/* new balance */

    printf("Enter account number (-1 to end): ");
    scanf("%d", &accnum);

    while (accnum != -1) {

	/* Data input */

	printf("Enter beginning balance: ");
	scanf("%f", &begbal);
	printf("Enter total charges: ");
	scanf("%f", &totcharges);
	printf("Enter total credits: ");
	scanf("%f", &totcreds);
	printf("Enter credit limits: ");
	scanf("%f", &credlim);

	/* New balance computation */

	newbal = begbal + totcharges - totcreds;

	/* Report printing */

	printf("Account:\t%d\n", accnum);
	printf("Credit limit:\t%.2f\n", credlim);
	printf("Balance:\t%.2f\n", newbal);

	newbal < credlim ?
	    printf("\n\n") : printf("Credit Limit Exceeded\n\n");

	/* Again */
	printf("Enter account number (-1 to end): ");
	scanf("%d", &accnum);
    }

    return 0;
}
