/* I here provide the modified bubble sort algorithm: it's
 * incapsulated in a function (despite exercise question) because
 * I need to use it in the following exercises  */

#include <stdio.h>
void bubble_sort(int array[], int array_length);
void print_array(int array[], int array_length);
int main(void)
{/*************/
    int a[10] = { 6, 4, 4, 2, 7, 5, 1, 8, 15, 12 };
    bubble_sort(a, 10);
    return 0;
}

void bubble_sort(int array[], int array_length)
{/********************************************/
    int pass;			/* pass counter */
    int i;			/* vector index */
    int hold;			/* temporary location */
    int flag;			/* =1 if after a pass, array is
				 * changed */
    for (pass = 1; pass < array_length; pass++) {
	flag = 0;
	printf("\nThe array before sorting pass\n");
	print_array(array, array_length);
	printf("let's sort it...\n");

	/* here the first change, with 1 substitueted by pass,
	   in order to diminish the comparison with pass
	   increasing */
	for (i = 0; i < array_length - pass; i++) {
	    if (array[i] > array[i + 1]) {
		hold = array[i];
		array[i] = array[i + 1];
		array[i + 1] = hold;
		print_array(array, array_length);

		/* here the second change; at the end of
		   the current for, flag will be 0 (default) if
		   and only if array[i] < array[i+1] for each
		   i: this mean that the array is already
		   sorted
		 */
		flag = 1;
	    }
	}
	printf("\n\n%d\n\n", flag);

	/* here the decision to continue or not the sorting */
	if (!flag)		/* if it's not changed */
	    break;		/* go to the next pass */
    }
}

void print_array(int array[], int array_length)
{/********************************************/
    int index;
    for (index = 0; index < array_length; index++)
	printf("%3d ", array[index]);
    printf("\n");
}
