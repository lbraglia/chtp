#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dice(void);

int main(void)
{

    int rolls, i;
    int dice_a, dice_b;
    int empirical_frequencies[11] = { 0 };
    int theoretical_frequencies[11] = { 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1 };

    srand(time(NULL));

    for (rolls = 1; rolls <= 36000; rolls++) {
	dice_a = dice();
	dice_b = dice();
	++empirical_frequencies[dice_a + dice_b - 2];
    }



    /* print table header */
    printf("\n\n");
    printf("%3s%10s%10s%10s\n", "sum", "abs_freq", "rel_freq", "thr_freq");

    /* print summaries */
    for (i = 2; i <= 12; i++)
	printf
	    ("%3d%10d%9.3f%11d\n",
	     i,
	     empirical_frequencies[i - 2],
	     (float) empirical_frequencies[i - 2] / 36000 * 36,
	     theoretical_frequencies[i - 2]
	    );

    printf("\n\n");

    return 0;
}


int dice(void)
{
    return 1 + rand() % 6;
}
