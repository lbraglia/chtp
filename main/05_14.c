#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));

    printf("a = %d\n", (1 + rand() % 5) * 2);
    printf("b = %d\n", (((rand() % 5) * 2) + 3));
    printf("c = %d\n", ((((rand() % 5) * 2) + 3) * 2));

    return 0;
}
