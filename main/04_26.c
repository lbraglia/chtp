#include<stdio.h>

int main(void)
{
   double pi = 0, x;
   int step = 0;

   /* header */
   printf("Step\tValue of Pi\n");	

   for(x=1; x<=1000001; x+=2)  {	
      if( (step%2) != 0) {
	 pi -= (4/x);
      } else {
	 pi += (4/x);
      }

      printf("%-4d\t%-11f\n", step, pi);
      step++;
   }
   return 0;
}
