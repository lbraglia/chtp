/* 
   Deitel & Deitel - "C How To Program"
   Exercise 6.30 - Sieve of Eratosthenes
 */
#include <stdio.h>

#define VEC_LEN 1000

void printPrimeNumbers(int eravector[], int len);


int main(void)
{

    int vector[VEC_LEN];
    int i, j;

    /* initialize the vector to 1 */
    for (i = 0; i < VEC_LEN; i++) {
	vector[i] = 1;
    }

    /* Sieve. j = number considered, i = divisor */
    for (i = 2; i < VEC_LEN; i++) {
	if (vector[i] == 1)
	    for (j = i + 1; j < VEC_LEN; j++) {
		/* if the number is already not prime go on */
		if (vector[j] == 0)
		    continue;
		/* else check if it's prime for i */
		else if (j % i == 0) {
		    vector[j] = 0;
		}
	    }
    }

    printPrimeNumbers(vector, VEC_LEN);

    return 0;
}


void printPrimeNumbers(int eravector[], int len)
{

    int i = 2;

    printf("Prime numbers [range %d-%d]: \n", i, VEC_LEN);
    for (; i < len; i++) {
	if (eravector[i] == 1)
	    printf("%d\n", i);
    }

}
