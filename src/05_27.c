#include <stdio.h>
#include <math.h>
#include <time.h>

int is_prime(int number);
int a_faster_prime(int number);

int main(void)
{

    int i;
    int time_a, time_b, time_c, time_d;


    time_a = time(NULL);
    for (i = 1; i <= 100000; i++) {
	if (is_prime(i))
	    printf("%d is a prime number\n", i);
    }
    time_b = time(NULL);


    time_c = time(NULL);
    for (i = 1; i <= 100000; i++) {
	if (a_faster_prime(i))
	    printf("%d is a prime number\n", i);
    }
    time_d = time(NULL);



    printf("\n\n");
    printf("Elapsed time\n============\n");
    printf("is_prime = %d seconds\n", time_b - time_a);
    printf("a_faster_prime = %d seconds\n", time_d - time_c);
    printf("\n\n");



    return 0;
}


int is_prime(int number)
{
    int divisor;

    for (divisor = 2; divisor <= number / 2; divisor++) {
	if (number % divisor == 0)
	    return 0;
    }

    return 1;

}


int a_faster_prime(int number)
{
    int divisor;

    for (divisor = 2; divisor <= (int) floor(sqrt(number)); divisor++) {
	if (number % divisor == 0)
	    return 0;
    }

    return 1;

}
