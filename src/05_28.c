#include<stdio.h>

int main()
{

    int num, final = 0;

    printf("\nInput Your Number: ");
    scanf("%d", &num);

    while (num > 0) {
	final = (final * 10) + (num % 10);
	num = num / 10;
    }
    printf("\nThe Reverse Number is: %d\n", final);

    return 0;
}
