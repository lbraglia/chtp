/* 
   Deitel & Deitel - "C How To Program"
   Exercise 7.12 - Poker
   Solution provided by Matteo Galvani 
   
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// declarations
void shuffle( int wDeck[][ 13 ] );
void deal_five( const int wDeck[][ 13 ], const char *wFace[], const char *wSuit[], 
               int wPlayer[][ 2 ] );
int testHand( const int wPlayer[][ 2 ] );


// start main
int
main( void )
{

   const char *suit[ 4 ] = { "Hearts", "Diamonds", "Clubs", "Spades" };
   
   const char *face[ 13 ] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
   
   int deck[ 4 ][ 13 ] = {{ 0 }};
   
   // Arrays holding cards dealt to players; one card for row; column0: face, column1=suit
   
   int player1[ 5 ][ 2 ] = {{ 0 }};
   int player2[ 5 ][ 2 ] = {{ 0 }};
   int player3[ 5 ][ 2 ] = {{ 0 }};
   int player4[ 5 ][ 2 ] = {{ 0 }};
   
   // this is a array of pointer to matrix of players cards; this was the hardest part
   int ((*friends)[5][2])[ 4 ] = { &player1, &player2, &player3, &player4 };
   
   srand( time( NULL ) );
   
   shuffle( deck );


   // deal cards to players and test hands
   int i;
   for (i = 0; i < 4; i += 1)
   {
      /* modified deal function to deal five cards to players;
         added the pointer to matrix (*friends) of players cards */
      deal_five( deck, face, suit, *friends[i] );
      testHand(*friends[i]);
   }
   
   return 0;

}//end main

void shuffle( int wDeck[][ 13 ] ){

   int row, column, card;
   
   for (card = 1; card <= 52; card += 1)
   {
      do
      {
         row = rand() % 4;
         column = rand() % 13;
      } while (wDeck[ row ][ column ] != 0);
   
   
      wDeck[ row ][ column ] = card;
   }
}// end shuffle


/* deal_five is a modified deal function that deliver 5 sorted cards to every player, and store it in wPlayer matrix; the variable card is now static so every time a player ask cards the last delivered are remembered.*/
void
deal_five( const int wDeck[ 4 ][ 13 ], const char *wFace[], const char *wSuit[], 
            int wPlayer[][ 2 ] )
{
   // bubblesort declaration is here since this is the only function that need sorting
   void bubblesort( int a[][ 2 ] );

   static int card = 1; // remember last card dealt
   int lastcard = card + 4; // deal next 5 cards
   int row, column;
   int i = 0, j = 0; // counters
   
   for (; card <= lastcard; card += 1)
   {
      for (row = 0; row <= 3; row += 1)
      {
         for (column = 0; column <= 12; column += 1)
         {
            if (wDeck[ row ][ column ] == card)
            {
               wPlayer[ i ][ j ] = column, wPlayer[ i++ ][ j + 1 ] = row;
            }
         }
      }
   }
   
   bubblesort(wPlayer);

}// end deal


/* test for tyhe result of the delivery*/
int
testHand( int const wPlayer[][ 2 ] )
{
   int r; // counters for columns and rows
   int couples = 0;
   int i;

   // first check for a straight if every card is equal to the next - 1
   if (wPlayer[0][0] == (wPlayer[1][0] - 1) && wPlayer[1][0] == (wPlayer[2][0] - 1) 
      && wPlayer[2][0] == (wPlayer[3][0] - 1) && wPlayer[3][0] == (wPlayer[4][0] - 1))
      {
         printf("Straight\n");
         return 1;
      }
   // then for a flush if column1 of the matrix of cards of the player hold all the same value
   else if (   wPlayer[0][1] == wPlayer[1][1] && wPlayer[1][1] == wPlayer[2][1] &&
               wPlayer[2][1] == wPlayer[3][1] && wPlayer[3][1] == wPlayer[4][1] )
      {
         printf("Flush\n");
         return 2;
      }
   /* if both of previous are false start a cicle to check the first 4 card 
   (checking the last is useless); it check every card with the next
   ( remember cards are sorted ) for card 0 and 1 check for pair if true check for 
   three of a kind if true check for a poker.
   For card 2 check for a tris but not for a poker (there are just 2 card left to check).
   If a poker or three of a kind is found exit function and return a value.
   For card 3 just check for a pair and store in "couples" that is used to test for pair
   or two pair */
   for (r = 0; r <= 3; r += 1)
   {
      if (wPlayer[r][0] == wPlayer[r+1][0])
      {
         if ( (r <= 2) && (wPlayer[r+1][0] == wPlayer[r+2][0]) )
         {
            if ( (r <= 1) && (wPlayer[r+2][0] == wPlayer[r+3][0]) )
            {
               printf( "Poker\n" );
               return 3;
            }
            else
            {
               printf( "Three of a kind\n" );
               return 4;
            }
         }
      couples++;
      }
      
   }
   
   switch (couples){
      
      case 2:
         printf( "Two pair\n");
         return 5;
         
      case 1:
        printf( "Pair\n" );
        return 6;

      default:
         printf( "Nada\n" );
         return -1;
      
   }
}

void
bubblesort( int a[][ 2 ] )
{
   int pass, i, hold;
   
    for( pass = 1; pass < 5; pass++){
      
      for( i = 0; i < 5 - 1; i++){
         if( a[i][0] > a[i + 1][0]){
            hold = a[i][0];
            a[i][0] = a[i + 1][0];
            a[i + 1][0] = hold;
         }
      }
   }
}
