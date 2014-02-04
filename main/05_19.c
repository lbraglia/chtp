#include <stdio.h>

void drawSquare(int side);

int main(void){
   int s;

   printf("Enter side: ");
   scanf("%d", &s);

   drawSquare(s);

   return 0;

}


void drawSquare(int side) {
   int col, row;

   for(row=1; row <= side; row++){
      for(col=1; col <= side; col++){
	 printf("*");
      }
      printf("\n");
   }
   

}
