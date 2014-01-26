#include <stdio.h>

int main()
{
    int somma = 0;
    int i;

    for (i = 2; i <= 30; i += 2) {
	somma += i;
	printf("somma fino %d: %d\n", i, somma);
    }

}
