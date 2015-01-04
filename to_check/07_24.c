#include <stdio.h>
#define SIZE 10

void quickSort(int *const array, int starting, int ending);

int main()
{
    int a[SIZE] = { 89, 17, 68, 45, 37, 2, 9, 5, 10, 15 };
    int i;
    quickSort(a, 0, SIZE - 1);
    printf("Data items in ascending order\n");
    for (i = 0; i < SIZE; i++) {
	printf("%d   ", a[i]);
    }
    printf("\n");
    return 0;
}

void quickSort(int *const array, int starting, int ending)
{
    int partition(int *const array, int starting, int ending);
    int index;
    if (starting == ending)
	return;
    else {
	index = partition(array, starting, ending);
	quickSort(array, starting, index - 1);
	quickSort(array, index, ending);
    }
}

int partition(int *const array, int starting, int ending)
{
    int i, j, hold, index = starting + 1;
    for (i = starting + 1; i <= ending; i++)
	if (array[starting] > array[i]) {
	    hold = array[i];
	    for (j = i; j >= starting + 1; j--)
		array[j] = array[j - 1];
	    array[starting] = hold;
	}
    return index;
}
