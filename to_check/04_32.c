#include <stdio.h>
#include <stdlib.h>

int main(){
  int size;
  printf( "Enter the (integer) rhombus size > " );
  scanf( "%d", &size );

  while( size < 1 ){
    printf( "Enter the (integer >= 1 ) rhombus size > " );
    scanf( "%d", &size );
  }
  
  int line = 1;

  int count;  
  for( count = size / 2; count >= -( size / 2 ); count-- ){
    int character;
    for( character = abs( count); character >  0   ; character-- ) printf( " " );
    for( character = 1          ; character <= line; character++ ) printf( "*" );
    line += ( count > 0 ) ? 2 : -2;
    
    printf( "\n" );
  }
  
  return 0;
}
