/* 
   10_10.c
 */

#include <stdio.h>

void displayBits(unsigned int x);

int main(void){

   unsigned int a  = 100000;
   printf("Before: ");
   displayBits(a);
   printf("\nAfter:  ");
   a >>= 4;
   displayBits(a);
   printf("\n");
   
   return 0;
}

void displayBits(unsigned int x){
   unsigned int counter;
   unsigned int mask = 1 << 31;
   for(counter = 1; counter <= 32; counter++){
      putchar( x & mask ? '1' : '0');
      x <<= 1;
      if (counter % 8 == 0)
	 putchar(' ');
   }
   
}
