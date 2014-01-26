#include <stdio.h>

int main()
{

    int side, curcol, currow = 1;

    printf("Insert the (integer) square side: ");
    scanf("%d", &side);


    while (currow <= side) {


	if (currow == 1) {	/* If the current row is the
				   first row ... */
	    curcol = 1;
	    while (curcol <= side) {	/*... go fill it */
		printf("*");
		curcol++;
	    }
	    printf("\n");
	    currow++;
	}



	else if (currow == side) {	/* The same if it's the last
					   one */
	    curcol = 1;
	    while (curcol <= side) {
		printf("*");
		curcol++;
	    }
	    printf("\n");
	    currow++;
	}

	else {			/* in every other row fill
				   only first and last
				   column */
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

    return 0;

}
