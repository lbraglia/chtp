#include <stdio.h>

int qualityPoints(int x);

int main()  
{
   int x;
   printf("Please enter the student's average: ");
   scanf("%d", &x);
   printf("%d\n", qualityPoints(x));
   return 0;
}

int qualityPoints(int x)
{

   if(x >= 90 && x <= 100)
      return 4;
   else if (x >= 80 && x <=89)
      return 3;
   else if (x >= 70 && x <= 79)
      return 2;
   else if (x >= 60 && x <= 69)
      return 1;
   else if (x >= 0 && x < 60)
      return 0;
   else				/* a little bit of checking */
      return -1;		/* wrong result!. eg mean >100 or
				   < 0 */
}
