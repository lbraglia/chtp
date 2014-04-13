#include<stdio.h>

int main(void){
   int a, b, c, x, y, z, step1, step2, counter1 = 4, counter2 = 1;
   for(step1=0; step1<5; step1++) {
      for(x=counter1; x>0; x--) {
	 printf(" ");
      }
      for(y= 1 + (2*step1); y>0; y--){
	 printf("*");
      }
      for(z=counter1; z>0; z--) {
	 printf(" ");
      }
      printf("\n");
      counter1--;
   }

   for(step2=3; step2>-1; step2--)  {
      for(a=counter2; a>0; a--) {
	 printf(" ");
      }
      for(b= 1 + (2*step2); b>0; b--){
	 printf("*");
      }
      for(c=counter2; c>0; c--) {
	 printf(" ");
      }
      printf("\n");
      counter2++;
   }
   
   return 0;
}
	 
		
