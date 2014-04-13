#include <stdio.h>

int main(void)
{

    int a;			/* first number */
    int b;			/* second */
    int c;			/* third */

    printf("Please insert the first number: ");
    scanf("%d", &a);
    printf("Please insert the second number: ");
    scanf("%d", &b);
    printf("Please insert the third number: ");
    scanf("%d", &c);

    if (a * a == b * b + c * c)
	printf("Yes they can\n");
    else if (b * b == a * a + c * c)
	printf("Yes they can\n");
    else if (c * c == a * a + b * b)
	printf("Yes they can\n");
    else
	printf("No they can't\n");

    return 0;
}
