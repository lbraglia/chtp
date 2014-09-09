#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* prototypes */
int dice(void);
void move(int *position, const int identificator);
void normalize_position(int *pos);
void check_for_winners(const int *tort_pos, const int *hare_pos, int *exit);
void print_situation(const int *tort_pos, const int *hare_pos);

/* ------------------------------------------------ */

/* MAIN */
int main(void)
{//-----------

   int tort_position = 1;       /* tortoise position */
   int hare_position = 1;       /* hare position */
   int exit = 0;                /* exit/end flag */
   int id;                      /* id, 1=tort 2=hare */
   
   srand(time(NULL));

   printf("BANG !!\nAND THEY'RE OFF!!\n");

   while ( !exit ) {

      /* Movement */
      for (id=1; id<=2; id++) {
         move(id == 1? &tort_position : &hare_position , id);
      }

      /* Print situation */
      printf("\n");
      print_situation(&tort_position, &hare_position);

      /* Check if anyone won, declare winner, and then exit */
      check_for_winners(&tort_position, &hare_position, &exit);

      sleep(1);
      printf("\n");
   }
      

   return 0;
}

/* ------------------------------------------------ */

int dice(void)
{//-----------
   return (rand() % 10 + 1);
}



void move(int *position, const int identificator)
{//----------------------
   int launch = dice();

   if (identificator == 1)      /* tortoise moves */

      switch (launch) {

      case  1:
      case  2:
      case  3:
      case  4:
      case  5:
         *position += 3;
         break;

      case  6:
      case  7:
         *position -= 6;
         break;

      case  8:
      case  9:
      case 10:
         *position += 1;
         break;

      }

   else if (identificator == 2) /* hare moves */

      switch (launch) {

      case  1:
      case  2:
         break;
      case  3:
      case  4:
         *position += 9;
         break;
      case  5:
         *position -= 12;
         break;
      case  6:
      case  7:
      case  8:
         *position += 1;
         break;
      case  9:
      case 10:
         *position -= 2;
         break;

      }


   /* if position < 1 or > 70 --> set to 1 or 70 */
   normalize_position( position );

}


void check_for_winners(const int *tort_pos, const int *hare_pos, int *exit)
{


      if ((*tort_pos == 70) && (*hare_pos >= 70)){
         printf ("It's a tie\n");
         *exit = 1;
      }
      else if (*tort_pos == 70) {
         printf ("Tortoise wins\n");
         *exit = 1;
      }
      else if (*hare_pos == 70) {
         printf ("Hare wins\n");
         *exit = 1;
      }

}

void print_situation(const int *tort_pos, const int *hare_pos)
{

   int counter;

   for (counter = 1; counter <= 70; counter++) {

      /* TODO improve this */
      if ( (counter == *tort_pos) &&  (counter == *hare_pos) )
         printf("O");
      else if (counter == *tort_pos)
         printf("T");
      else if (counter == *hare_pos)
         printf("H");
      else if (counter == 1)
         printf("S");
      else if (counter == 70)
         printf("F");
      else if (counter % 10 == 0)
         printf("|");
      else
         printf(".");

   }
   printf("\n");
   printf("Tortoise: %d\nHare: %d\n", *tort_pos, *hare_pos);
   printf("\n");

}


void normalize_position(int *pos)
{
   if (*pos < 1)
      *pos = 1;
   else if (*pos > 70)
      *pos = 70;
}
