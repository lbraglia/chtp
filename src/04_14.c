#include <stdio.h>

int main()
{
    int cumprod = 1, number, n;
    printf("Enter n: ");
    scanf("%d", &n);

    for (; n >= 1; n--) {
	cumprod *= n;
    }

    printf("n! = %d\n", cumprod);

    return 0;
}
