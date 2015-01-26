/* 
   13_10: SUMARRAY
 */
#include <stdio.h>

#define SUMARRAY(array, nelem) \
    while(i < nelem){ sum += array[i]; i++;}
#define DIM 3

int main(void)
{
    int i = 0, sum = 0;
    int array[DIM] = { 1, 2, 3 };
    SUMARRAY(array, DIM);
    printf("Sum: %d\n", sum);
    return 0;
}
