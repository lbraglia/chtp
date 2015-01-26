/* 
   13_05: SUM macro
 */
#include <stdio.h>

#define SUM(a, b) ( (a) + (b) )

int main (void){

    int x = 5;
    int y = 8;
    
    printf("Sum of x and y is %d\n", SUM(x,y));

    return 0;
}
