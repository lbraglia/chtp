#include <stdio.h>

int main()
{
    int number, cumprod = 1, oldcumprod;

    for (number = 1; number <= 15; number += 2) {
	oldcumprod = cumprod;
	printf("%6d * %2d = %7d\n", oldcumprod, number, cumprod *= number);
    }

    return 0;

}
