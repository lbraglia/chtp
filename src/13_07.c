/* 
   13_07: MINIMUM3
 */
#include <stdio.h>

#define MINIMUM2(a, b) ( (a) < (b) ? (a) : (b) )
#define MINIMUM3(a, b, c) ( MINIMUM2(a, b) < (c) ? MINIMUM2(a, b) : (c) )

int main (void){

    int x = 0;
    int y = 0;
    int z = 0;

    printf("Enter three integers: ");
    scanf("%d %d %d", &x, &y, &z);
    
    printf("Minimum between %d, %d and %d is %d\n",
	   x, y, z,
	   MINIMUM3(x,y,z));

    return 0;
}
