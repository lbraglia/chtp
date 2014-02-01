/* 
   03_47a: simple factorial

 */

#include <stdio.h>

int main(void) {

   int number = 0;
   int factorial = 1;
   int backup;

   printf("enter a positive integer: ");
   scanf("%d", &number);

   /* Control data input */
   while(number < 0) {
      printf("enter a POSITIVE integer: ");
      scanf("%d", &number);
   }

   backup = number;

   /* Calculating factorial */
   while(number != 0) {
      factorial *= number;
      number--;
      
   }

   /* printing */
   printf("%d! = %d\n", backup, factorial);

   return 0;
}
