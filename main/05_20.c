#include <stdio.h>

int square(int dimension, char character);


int main(void)
{
    int dim;
    char chr;

    printf("Enter dimension (int) & character (char) of the square: ");
    scanf("%d %c", &dim, &chr);
    printf("\n");
    square(dim, chr);
    printf("\n");

    return 0;
}


int square(int dimension, char character)
{

    int colcounter, rowcounter;

    for (rowcounter = 1; rowcounter <= dimension; rowcounter++) {
	for (colcounter = 1; colcounter <= dimension; colcounter++) {
	    printf("%c", character);
	}

	printf("\n");
    }

    return 0;
}
