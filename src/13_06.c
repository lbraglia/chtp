/* 
   13_06: MINIMUM2
 */
#include <stdio.h>

#define MINIMUM2(a, b) ( (a) < (b) ? a : b )

int main (void){

    int x = 0;
    int y = 0;

    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);
    
    printf("Minimum between %d and %d is %d\n", x, y, MINIMUM2(x,y));

    return 0;
}
