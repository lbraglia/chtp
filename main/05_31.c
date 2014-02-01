#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip(void);


int main(void)
{
    int face, counter, totheads = 0, tottails = 0;
    srand(time(NULL));

    for (counter = 1; counter <= 10; counter++) {
	face = flip();
	printf("%s\n", face ? "Heads" : "Tails");
	if (face == 1)
	    totheads++;
	else if (face == 0)
	    tottails++;
    }

    printf("\n\n");
    printf("Tot Heads\t%2d\n", totheads);
    printf("Tot Tails\t%2d\n", tottails);
    printf("\n\n");
    return 0;
}

int flip(void)
{
    return rand() % 2;
}
