#include <stdio.h>

int main(void)
{

    int line;			/* line number */
    int astsk;			/* asterisks counter */
    int blank;			/* blank counter */


    /* A */
    printf("(A)\n");
    for (line = 1; line <= 10; line++) {
	for (astsk = 1; astsk <= line; astsk++)
	    printf("*");
	printf("\n");
    }
    printf("\n");


    /* B */
    printf("(B)\n");
    for (line = 10; line >= 1; line--) {
	for (astsk = 1; astsk <= line; astsk++)
	    printf("*");
	printf("\n");
    }
    printf("\n");


    /* C */
    printf("(C)\n");
    for (line = 1; line <= 10; line++) {

	/* blank = line - 1 */
	for (blank = 1; blank <= line - 1; blank++)
	    printf(" ");
	/* astsk = 11 - line */
	for (astsk = 1; astsk <= 11 - line; astsk++)
	    printf("*");

	printf("\n");
    }
    printf("\n");


    /* D */
    printf("(D)\n");
    for (line = 1; line <= 10; line++) {

	/* blank = 10 - line */
	for (blank = 1; blank <= 10 - line; blank++)
	    printf(" ");
	/* astsk = line */
	for (astsk = 1; astsk <= line; astsk++)
	    printf("*");

	printf("\n");
    }
    printf("\n");



    return 0;

}
