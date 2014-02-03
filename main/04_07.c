/* 
   04_07.c
 */

#include <stdio.h>

int main (void) {

   int x;
   
   /* a) */
   printf("a) ");
   for (x = 1; x <= 7; x++) {
      printf("%d ",x);
   }

   /* b) */
   printf("\nb) ");
   for( x=3; x <= 23; x += 5) {
      printf("%d ",x);
   }

   /* c) */
   printf("\nc) ");
   for( x=20; x >= -10; x -= 6) {
      printf("%d ",x);
   }


   /* d) */
   printf("\nd) ");
   for( x=19; x <= 51; x += 8) {
      printf("%d ",x);
   }
   printf("\n");



   return 0;
}
