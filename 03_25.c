#include <stdio.h>

int main()
{
    int counter = 1;

    printf("N \t 10*N \t 100*N \t 1000*N \n");

    while (counter <= 10) {
	printf("%d \t %d \t %d \t %d \n", counter, counter * 10,
	       counter * 100, counter * 1000);
	counter++;
    }

    return 0;

}
