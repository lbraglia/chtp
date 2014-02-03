#include<stdio.h>

int main(void)
{
   double pi = 0, x;
   int step = 0;
   printf("%4s  %11s\n", "Step" , "Value of Pi");	
   for(x=1; x>0; x+=2)  {	
      if( (step%2) != 0) {
	 pi -= (4/x);
      } else {
	 pi += (4/x);
      }

      printf("%-4d  %-11f\n", step, pi);
      step++;
   }
   return 0;
}
