#include <stdio.h>
#include <math.h>

int mcd(int alpha, int beta);
int min(int a, int b);


int main(void)
{
    int x, y;

    printf("Enter two integers: ");
    scanf("%d%d", &x, &y);
    printf("mcd beetween %d and %d is %d\n", x, y, mcd(x, y));

    return 0;
}


int mcd(int alpha, int beta)
{

/* if alpha and beta are multiple, here we have a fast function
 * exit */

    int divisor = min(alpha, beta);

    if ((alpha % divisor == 0) && (beta % divisor == 0))
	return divisor;


/* if it's not exited in the last istruction, now I start
 * iterating the search of mcd from min(alpha,beta)/2 */

    for (divisor = (int) ceil(min(alpha, beta) / 2); divisor >= 1;
	 divisor--) {
	if ((alpha % divisor == 0) && (beta % divisor == 0)) {
	    return divisor;
	    break;
	}
    }

}


int min(int a, int b)
{
    int min = a;

    if (b < a)
	min = b;

    return min;
}
