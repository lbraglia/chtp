/* 
   03_26.c
 */

#include <stdio.h>

int main(void)
{

    int a = 3;

    /* Print header */
    printf("A\tA+2\tA+4\tA+6\n\n");

    while (a <= 12) {
	printf("%d\t%d\t%d\t%d\n", a, a + 2, a + 4, a + 6);
	a = a + 3;

    }
    return 0;
}
