#include <stdio.h>

int main(void)
{
    int size;
    int line = 1;
    int count;
    int character;

    printf("Enter the (integer) rhombus size > ");
    scanf("%d", &size);

    while (size < 1 || size > 19 || !(size % 2)) {
	printf("Enter the (integer 1,3,5...19) rhombus size > ");
	scanf("%d", &size);
    }

    for (count = size / 2; count >= -(size / 2); count--) {
	for (character = (count >= 0 ? count : -count); character > 0;
	     character--)
	    printf(" ");
	for (character = 1; character <= line; character++)
	    printf("*");
	line += (count > 0) ? 2 : -2;

	printf("\n");
    }

    return 0;
}
