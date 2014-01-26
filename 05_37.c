#include <stdio.h>
#include <math.h>

long mypow(int base, int exponent);


int main(void)
{/***********/
    long b, e, again;

    do {
	printf("Enter base: ");
	scanf("%d", &b);
	printf("Enter exponent: ");
	scanf("%d", &e);
	printf("%d ^ %d = %d\n", b, e, mypow(b, e));
	printf("again? 1 (yes) or 0 (no): ");
	scanf("%d", &again);
    }

    while (again);


    return 0;
}


long mypow(int base, int exponent)
{/*********************************/

    if (exponent == 0)
	return 1;
    else if (base == 1)
	return base;
    else
	return base * mypow(base, exponent - 1);
}
