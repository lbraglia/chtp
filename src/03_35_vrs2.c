/*Deitel's C How to program. Solution to problem #3.35, 2nd version*/
#include <stdio.h>


int main(void)
{
    int digits, result, remainder;
    int counter = 1, divisor = 10000;
    int first, second, fourth, fifth;

    printf("Please enter a five digit number: ");
    scanf("%d", &digits);

    while (counter <= 5) {

	/* follow one loop with pen and paper to get the idea */
	remainder = digits % divisor;
	result = (digits - remainder) / divisor;
	printf("Digit %d = %d\n", counter, result);

	/* until this chapter in the book, the author assumes we
	 * don't know arrays */
	if (counter == 1)
	    first = result;
	if (counter == 2)
	    second = result;
	if (counter == 4)
	    fourth = result;
	if (counter == 5)
	    fifth = result;

	counter++;
	digits = remainder;
	divisor = divisor / 10;

    }

    if (first == fifth && second == fourth) {
	printf("The number is in fact PALINDROME!\n");
    } else {
	printf("The number is not PALINDROME!\n");
    }


    return (0);
}
