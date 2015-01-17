/* 
   10_14.c
 */

#include <stdio.h>

void showBits(unsigned short int x);

unsigned short int packCharacters(unsigned char a, unsigned char b);

void unpackCharacters(unsigned short int x,
		      unsigned char *a, unsigned char *b);


int main(void)
{

    unsigned char a;
    unsigned char b;
    unsigned short int c;

    printf("Enter 2 characters: ");
    scanf("%c %c", &a, &b);

    /* packing */
    printf("\npacked = ");
    c = packCharacters(a, b);
    showBits(c);
    printf("\n");

    /* cleaning old values */
    a = b = '\0';


    /* unpacking */
    unpackCharacters(c, &a, &b);
    printf("%6c = ", a);
    showBits(a);
    printf("\n%6c = ", b);
    showBits(b);
    printf("\n");

    return 0;
}


unsigned short int packCharacters(unsigned char a, unsigned char b)
{

    return ((a << 8) | b);

}

void unpackCharacters(unsigned short int x,
		      unsigned char *a, unsigned char *b)
{


    /* 0xff00 is 65280 in hexadecimal, but easier/more useful to think of in
     * term of binary digits: look at numeric systems appendix, or test with
     * showBits(0xff00)  */
    unsigned short int mask1 = 0xff00;
    /* same below */
    unsigned short int mask2 = 0x00ff;
    /* char a: since here i've used only 2 bytes for saving space, and right
       moving leave unpredictable bits on your left, i'll use a further mask
       to clean */

    *a = (((x & mask1) >> 8) & mask2);
    *b = x & mask2;

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
