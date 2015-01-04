#include <stdio.h>

/* 03_21.c: gross wage */

int main(void)
{

    int hours = 0;
    float hourly_rate = 0.0;
    float salary = 0.0;

    printf("Enter # of hours worked (-1 to stop): ");
    scanf("%d", &hours);

    while (hours != -1) {
	printf("Enter hourly rate of the worker ($00.00): ");
	scanf("%f", &hourly_rate);

	if (hours <= 40) {
	    salary = hours * hourly_rate;
	} else if (hours > 40) {
	    salary =
		(40 * hourly_rate) + (hours - 40) * (hourly_rate * 1.5);
	}

	printf("Salary is $%.2f\n\n", salary);
	printf("Enter # of hours worked (-1 to stop): ");
	scanf("%d", &hours);

    }

    return 0;

}
