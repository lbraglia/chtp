/* 
   03_27: largest of 10 numbers
 */


#include <stdio.h>

int main (void) {
   
   int counter = 1;
   float number = 0.0;
   float largest = 0.0;

   while (counter <= 10 ) {
      printf("Enter number %d of 10: ", counter);
      scanf("%f", &number);
      if (counter==1) {
	 largest = number;
      } else {
	 largest = (number > largest ? number : largest);
      }

      counter++;
   }
   
   printf("Largest is %.2f\n", largest);
   return 0;


}
