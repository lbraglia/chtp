/* 
   05_25.c min of three floating numbers
 */

#include <stdio.h>


double fpmin(double first, double second, double third);


int main(void){
   double a,b,c;

   printf("Enter three floating point number: ");
   scanf("%lf%lf%lf", &a, &b, &c);

   printf("\n    min\n%7.3f\n", fpmin(a,b,c));

   return 0;

}


double fpmin(double first, double second, double third){

   double min;

   min = first;
   if (second < min)
      min = second;
   if (third < min)
      min = third;

   return (min);

}
