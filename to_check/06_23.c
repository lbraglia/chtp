/* Deitel & Deitel - "C++ How To Program"
Exercise 6.23 - Turtle graphics 
Solution provided by Matteo Galvani */


#include <stdio.h>
#include <math.h>

#define FLOOR 50
#define INIT_XPOS 5 // Initial X
#define INIT_YPOS 5 // Initial Y
#define PI 3.14159265

// declarations
void walk(float dir, int pen);
void print_matrix();


int table[ FLOOR ][ FLOOR ] = { 0 };
int xpos = INIT_XPOS;
int ypos = INIT_YPOS;

int main(){
   
   int input;
   int pen = 0; // 0 pen up, 1 pen down
  
   float dir = 0;   // turtle direction in degree
   
   while(1){
   
   /* This is for debug
   printf("posizione x=%d, y=%d\n", xpos, ypos);
   printf("direzione: %f\n", dir);
   printf("Cos dir: %f\n", cos(dir * PI / 180));
   printf("Sin dir: %f\n", sin(-(dir * PI / 180)));*/
   printf( "Insert command\n\
            1) Pen UP\n\
            2) Pen DOWN\n\
            3) Turn right\n\
            4) Turn left\n\
            5) Walk x steps\n\
            6) Print matrix\n\
            9) End\n");
            
   scanf("%d", &input);
   
   switch (input){
      
      case 1:
      case 2:
         pen = input - 1;
         break;
         
      case 3:
         dir -= 90;
         break;
         
      case 4:
         dir += 90;
         break;
         
      case 5:
         walk(dir, pen);
         break;
         
      case 6:
         print_matrix();
         break;
         
      case 9:
         print_matrix();
         return 0;
         
      default:
         printf( "Scelta errata.. riprova");
   
   
   
   }//end switch
}//end while

} //end main

void walk(float dir, int pen){
   
   int step;
   int i;
   printf( "Quanti passi?\n");
   scanf("%d", &step);
   
   // Use sin and cos to set 
   
   for (i = 0; i < step; i += 1)
   {
      xpos += round(cos(dir * PI / 180));
         if (xpos < 0)
         {
            xpos = 0;
         }
         else if (xpos > FLOOR)
         {
            xpos = FLOOR;
         }
      ypos += round(sin(-(dir * PI / 180)));
         if (ypos < 0)
         {
            ypos = 0;
         }
         else if (ypos > FLOOR)
         {
            ypos = FLOOR;
         }
      if (pen == 1)
      {
         table[ypos][xpos] = 1;
      }
   }


}//end walk

void print_matrix(){

   int i, j, k;
   
   for (i = 0; i < FLOOR * 3; i += 1)
   {
      printf("-");}
   
   for (j = 0; j < FLOOR; j += 1)
   {
      printf("\n|");
         for (k = 0; k < FLOOR; k += 1)
         {
            printf(table[j][k]?" # ":"   ");
         }
      printf("|");
   }
   printf("\n");
   


}//end print_matrix
