#include <stdio.h>

int main(){

   long int binary;

   int size = 1;
   int next = 1;
   long int mult = 10;
   
   int decimal     =  0;
   long int value  =  1;
   long int module = 10;
  
   printf( "Binary  -> " );
   scanf( "%ld", &binary );

   while( next ){
      if( binary >= mult ){
	 size++;
	 mult *= 10;
      } else next = 0;
   }
   
   while( size-- ){
      int pos = ( binary % module ) / ( module / 10 );
      module *= 10;
      decimal += ( pos >= 1 ? 1 : 0 ) * value;
      value *= 2;
   }

   printf( "Decimal -> %d\n", decimal );
  
   return 0;
}
