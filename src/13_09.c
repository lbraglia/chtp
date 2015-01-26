/* 
   13_09: PRINTARRAY
 */
#include <stdio.h>

#define PRINTARRAY(array, nelem) \
    while(i < nelem){ printf("%d ",array[i]); i++;}
#define DIM 3

int main(void)
{
    int i = 0;
    int array[DIM] = { 1, 2, 3 };
    PRINTARRAY(array, DIM);
    printf("\n");
    return 0;
}
