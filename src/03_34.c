#include <stdio.h>

int main()
{
    int side, curcol, currow = 1;
    int side_min = 1;
    int side_max = 20;

    printf("Insert the (integer between %d and %d) square side : ",
	   side_min, side_max);
    scanf("%d", &side);

    if (side < side_min)
	printf("Side must be > %d\n", side_min);
    else if (side <= side_max) {

	while (currow <= side) {
	    /* If the current row is the first row ... */
	    if (currow == 1) {
		curcol = 1;
		while (curcol <= side) {	/*... go fill it */
		    printf("*");
		    curcol++;
		}
		printf("\n");
		currow++;
	    }
	    /* The same if it's the last one */
	    else if (currow == side) {
		curcol = 1;
		while (curcol <= side) {
		    printf("*");
		    curcol++;
		}
		printf("\n");
		currow++;
	    } else {		/* in every other row fill only first and last column */
		curcol = 1;
		while (curcol <= side) {
		    if (curcol == 1)
			printf("*");
		    else if (curcol == side)
			printf("*");
		    else
			printf(" ");
		    curcol++;
		}
		printf("\n");
		currow++;
	    }
	}

    } else
	printf("side must be <= %d\n", side_max);

    return 0;
}
