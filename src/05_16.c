#include <stdio.h>

long int integerPower(int base, unsigned int exponent);

int main(void){
   int b;
   unsigned int exp;

   printf("Enter base: ");
   scanf("%d", &b);
   printf("Exponent base: ");
   scanf("%u", &exp);

   printf("\nBase^Exponent = %15li\n", integerPower(b,exp));
   return 0;

}

long int integerPower(int base, unsigned int exponent){
   unsigned int x = 1;
   long int result = 1;

   for (x = 1; x <= exponent; x++){
      result *= base;
   }

   return result;   
}
