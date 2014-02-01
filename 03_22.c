/* 
   03_21.c: --n vs n--
*/

#include <stdio.h>

int main (void) {

   int n=0;
   int backup;

   printf("Enter an integer (default=0). n=");
   scanf("%d", &n);

   backup = n;
   
   printf("n-- prints %d\n", backup--);
   printf("--n prints %d\n", --n);



   return 0;

}
