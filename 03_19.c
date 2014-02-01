/* 
   03_19.c sales in chemical industry
 */

#include <stdio.h>

int main(void) {

   float sales=0;

   printf("Entry sales in dollars (-1 to end): ");
   scanf("%f", &sales);

   while(sales != -1) {

      printf("Salary is %.2f\n\n", 200.00 + sales*0.09);
      printf("Entry sales in dollars (-1 to end): ");
      scanf("%f", &sales);

   }
   
   return 0;


}
