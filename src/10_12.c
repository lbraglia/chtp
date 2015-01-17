/* 
   10_12.c
 */

#include <stdio.h>

void showBits(unsigned int x);
unsigned int power2(unsigned int number, unsigned int pow);

int main(void){

   printf("%2u =\t", 4);
   showBits(4);
   printf("\n");
   
   printf("%2u =\t", power2(4, 3) );
   showBits(power2(4, 3));
   printf("\n");
   
   return 0;
}

unsigned int power2(unsigned int number, unsigned int pow){

   return number << pow;

}

void showBits(unsigned int x){
   unsigned int mask = 1 << 31;
   unsigned int i;

   for(i = 1; i <= 32; i++){
      putchar( x & mask? '1': '0');
      if (i % 8 == 0) putchar(' ');
      x <<= 1;
   }

}
