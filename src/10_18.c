/* 
   10_18.c
 */

#include <stdio.h>

void showBits(unsigned int x);

int main(void)
{

    unsigned int a = 0x8badf00d;
    /* http://en.wikipedia.org/wiki/Hexspeak :) 
       i'm assuming 4 byte integer here (my system), but the function below
       should work fine on 2-byte integer systems too */
    showBits(a);
    printf("\n");
    return 0;
}

void showBits(unsigned int x)
{

    unsigned int i;
    unsigned int mask;
    size_t intBits = sizeof(int) * 8;

    mask = 1 << (intBits - 1);

    for (i = 1; i <= intBits; i++) {
	putchar(x & mask ? '1' : '0');
	if ((i % 8) == 0)
	    putchar(' ');
	x <<= 1;
    }

}
