#include <stdio.h>

int main(){
  int line, character;

  printf( "(A)\t\t(B)\t\t(C)\t\t(D)\n" );

  for( line = 0; line < 10; line++ ){

    /*
     *          	
     **         	
     ***        	
     ****       	
     *****      	
     ******     	
     *******    	
     ********   	
     *********  	
     ********** 	
     */
    for( character =  0; character <= line; character++ ) printf( "%c", '*' );
    for( character = 10; character  > line; character-- ) printf( "%c", ' ' );
    printf( "\t" );

    /*
     ********** 	
     *********  	
     ********   	
     *******    	
     ******     	
     *****      	
     ****       	
     ***        	
     **         	
     *          	
     */
    for( character = 10; character  > line; character-- ) printf( "%c", '*' );
    for( character =  0; character <= line; character++ ) printf( "%c", ' ' );
    printf( "\t" );

    /*
     **********	
      *********	
       ********	
        *******	
         ******	
          *****	
           ****	
            ***	
             **	
              *	
     */
    for( character =  0; character < line; character++ ) printf( "%c", ' ' );
    for( character = 10; character > line; character-- ) printf( "%c", '*' );
    printf( "\t" );

    /*
              *	
             **	
            ***	
           ****	
          *****	
         ******	
        *******	
       ********	
      *********	
     **********	
     */
    for( character = 10; character  > line; character-- ) printf( "%c", ' ' );
    for( character =  0; character <= line; character++ ) printf( "%c", '*' );

    printf( "\n" );
  }

  return 0;
}
