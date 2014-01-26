#include <stdio.h>

int main()
{
    /*starting number ... */
    int number;

    /*... and (its) digits number */
    int one, two, thr, fou, fiv;

    printf("Enter a five digits number: ");
    scanf("%d", &number);

    one = number / 10000;
    two = (number % 10000) / 1000;
    thr = ((number % 10000) % 1000) / 100;
    fou = (((number % 10000) % 1000) % 100) / 10;
    fiv = ((((number % 10000) % 1000) % 100) % 10) / 1;

    printf("%d %d %d %d %d\n", one, two, thr, fou, fiv);

    return 0;

}
