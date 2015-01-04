#include<stdio.h>

int main(void)
{
    int side1, side2, hyp, counter = 1;
    printf("Number  SideOne  SideTwo  Hypotenuse");
    for (side1 = 1; side1 <= 500; side1++) {
	for (side2 = 1; side2 <= 500; side2++) {
	    for (hyp = 1; hyp <= 500; hyp++) {
		if ((side1 * side1) + (side2 * side2) == (hyp * hyp)) {
		    printf("%6d  %7d  %7d  %10d\n", counter, side1, side2,
			   hyp);
		    counter++;
		}
	    }
	}
    }
    return 0;
}
