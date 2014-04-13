/* here I do not implement "sort and search" because it would be
 * time consuming for a smile array of 20 scalars: I'll use
 * linear search */

#include <stdio.h>

int it_exists(int the_number, int the_array[], int search_limit);

int main(void)
{

    int i;			/* a counter */
    int numbers[20] = { 0 };	/* the vector to be filled with
				   numbers inserted */
    int a_number;		/* the number considered at the moment */
    int inserted_number = 0;	/* # of number, not duplicated,
				   saved in the array */


    for (i = 0; i <= 20 - 1; i++) {
	printf("Enter a number beetween 10 and 100: ");
	scanf("%d", &a_number);

	while ((a_number < 10) || (a_number > 100)) {
	    printf("The number must be beetween 10 and 100\n");
	    printf("Enter a number beetween 10 and 100: ");
	    scanf("%d", &a_number);
	}


	if (it_exists(a_number, numbers, inserted_number));	/* do nothing */
	else {
	    printf("\nHey, %d is a new number!\n", a_number);
	    numbers[inserted_number] = a_number;
	    ++inserted_number;	/* I save a new number in the
				   memory array only if it's unique */
	}

    }

}


int it_exists(int the_number, int the_array[], int search_limit)
{

    int j;

    for (j = 0; j < search_limit; j++)
	if (the_number == the_array[j])
	    return 1;

    /* otherwise ... */

    return 0;

}
