#include <stdio.h>

int main()
{

    int side, curcol, currow = 1;

    printf("Insert the (integer) square side: ");
    scanf("%d", &side);

    while (currow <= side) {
	curcol = 1;

	while (curcol <= side) {
	    printf("*");
	    curcol++;
	}

	printf("\n");
	currow++;

    }

    return 0;
}
