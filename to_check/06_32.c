/* 
   Deitel & Deitel - "C How To Program"
   Exercise 6.32 - Recursive Selection Sort
   Solution provided by Matteo Galvani 
   
*/
#include <stdio.h>
 
 // Array to sort.
 int array[ 8 ] = {5, 45, 425, 14, 94, 1, 1000, 84 };
 
 // Declarations
 void printArr(int arr[ 8 ]);
 void rSelectionSort( int arr[ 8 ], int initPos);
 
 int main(void){
 
   printf( "original unordered array:\n");
   printArr(array);
   
   rSelectionSort(array, 0);
   printf( "Ordered array:\n");
   printArr(array);
   
   return 0;
   
 } //end main
 
 
 // Recursive selection sort
 void rSelectionSort( int arr[ 8 ], int initPos){
   
   // if there is just one element left (initPos points the last element) the array is sorted
   if (initPos == 7)
   {
      return;
   }
   else
   {  
      int tmp = arr[ initPos ]; // save the first value in tmp
      int j;
         
         // cicle the array starting from the next value
         for (j = initPos + 1; j < 8 ; j += 1)
         {  
            
            if (arr[ j ] < arr[ initPos ]) // if 'j' the value is smaller than the first
            {
               arr[ initPos ] = arr[ j ]; // place 'j' value as first
               arr[ j ] = tmp; // place initPos in 'j' position
               tmp = arr[ initPos ]; // save the new initPos value in tmp
            }
         }
       rSelectionSort(arr, initPos + 1); // recall the function starting from next value
   }
 
 
 
 }//end rSelectionSort
 
 void printArr(int arr[ 8 ]){
 
   int i;
   for (i = 0; i < 8; i += 1)
   {
      printf( "%d ", array[ i ]);
   }
   printf( "\n" );
 
 }//end printArr.
