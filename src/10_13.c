/* 
   10_13.c
 */

#include <stdio.h>

void showBits(unsigned short int x);
unsigned short int packCharacters(unsigned char a, unsigned char b);

int main(void)
{

    unsigned char a;
    unsigned char b;
    unsigned short int c;

    printf("Enter 2 characters: ");
    scanf("%c %c", &a, &b);

    printf("You inserted:\n");
    printf("%6c = ", a);
    showBits(a);
    printf("\n%6c = ", b);
    showBits(b);

    printf("\npacked = ");
    c = packCharacters(a, b);
    showBits(c);
    printf("\n");

    return 0;
}


unsigned short int packCharacters(unsigned char a, unsigned char b)
{

    return ((a << 8) | b);

}


void showBits(unsigned short int x)
{
    unsigned int i;
    unsigned short int mask = 1 << 15;

    for (i = 1; i <= 16; i++) {
	putchar(x & mask ? '1' : '0');
	if ((i % 8) == 0)
	    putchar(' ');
	x <<= 1;
    }

}
