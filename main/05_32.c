#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
   
   int a,b,result;

   srand(time(NULL));
   
   a = rand()%9 + 1;
   b = rand()%9 + 1;

   printf("How much is %d times %d? :", a, b);
   scanf("%d", &result);

   while(result != a*b) {
      printf("No please try again: ");
      scanf("%d", &result);

   }
   
   printf("Very good!\n");
   return 0;
   
   

}
