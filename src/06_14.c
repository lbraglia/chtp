/* Here you can find not the solutions but only the two functions
 * (with little improvements, described under definition header.
 * In the file I will use vector and array as synonims.
 */  
    
#include <stdio.h>
void mode(int array[], int array_length);
void set_to_0(int array[], int array_length);
void bubble_sort(int array[], int array_length);
void print_array(int array[], int array_length);
float median(int vector[], int vect_length);

#define SIZE 6
int main(void) 
{/***********/
    int a[SIZE] = { -3, 2, 4, -1, -3, 5 };
    printf("\n\n");
    mode(a, SIZE);
    printf("\n\n");
    printf("median(a) = %.2f\n", median(a, SIZE));
    printf("\n\n");
    return 0;
}
void mode(int array[], int array_length) 
{/*************************************/
    
/* a simpler function to perform mode calculation, that handle
 * multimode distributions and nonpositive array values; it uses
 * bubble sort for ordering.
 */ 
    int i, j;		/* some generic indexes used in for
				 * statements*/
    int freq[array_length];
    int max[array_length];
    
	/*
	   Now I initialize freq and max to 0; I could't to this in
	   declaration because of:
	   
	   06_14_mode.c:32: error: variable-sized object may not be
	   initialized
	 */ 
	set_to_0(max, array_length);
    set_to_0(freq, array_length);
    
      /* print_array( max, array_length ); */
      /* print_array( freq, array_length ); */
	
	/* a way to handle non-positive values is to sort the array */ 
	printf("original vector is\n");
    print_array(array, array_length);
    printf("let's sort it\n");
    bubble_sort(array, array_length);
    printf("after sorting ...\n");
    print_array(array, array_length);
    
	/* now we fill the frequency array */ 
    int last_position = 0;	/* index of the first scalar with
				   the same value as current one */
    freq[0] = 1;
    for (i = 1; i < array_length; i++)
	 {
	if (array[i] == array[last_position])
	    ++freq[last_position];
	
	else
	     {
	    ++freq[i];
	    last_position = i;
	    }
	}
    printf("frequency vector of sorted one ...\n");
    print_array(freq, array_length);
    
	/* now we have to find freq[] max(s) */ 
    int max_position = 0;	/* let's assume the first scalar is
				   the max of the array */
    max[0] = 1;
    for (i = 1; i < array_length; i++)
	 {
	if (freq[i] > freq[max_position])
	     {
	    set_to_0(max, i - 1);
	    max[i] = 1;
	    max_position = i;
	    }
	
	else if (freq[i] == freq[max_position])
	    max[i] = 1;
	}
    printf("max vector ...\n");
    print_array(max, array_length);
    printf("and finally mode is (are) ...\n\n\t");
    for (i = 0; i < array_length; i++)
	if (max[i])
	    printf("[%2d] ", array[i]);
    printf("\n\n");
}
float median(int vector[], int vect_length) 
{/***************************************/
    int a, b;			/* even-scalars vector middle
				 * elements ... */
    float mean;		/* ... and their mean */
    if (vect_length % 2 == 0)
	 {
	a = vector[(vect_length / 2) - 1];
	b = vector[vect_length / 2];
	mean = ((float) (a + b)) / 2;
	return mean;
	}
    
    else
	return vector[vect_length / 2];
}
void bubble_sort(int array[], int array_length) 
{/********************************************/
    int pass;			/* pass counter */
    int i;			/* vector index */
    int hold;			/* temporary location */
    int flag;			/* =1 if after a pass, array is
				 * changed */
    for (pass = 1; pass < array_length; pass++)
	 {
	    flag = 0;
	    
	    /* printf("\nThe array before sorting pass\n"); */
	    /* print_array(array, array_length); */
	    /* printf("let's sort it...\n"); */
	    for (i = 0; i < array_length - pass; i++)
	     {
	    if (array[i] > array[i + 1])
		 {
		hold = array[i];
		array[i] = array[i + 1];
		array[i + 1] = hold;
		print_array(array, array_length);
		flag = 1;
		}
	    }
	printf("\n\n%d\n\n", flag);
	if (!flag)		/* if it's not changed */
	    break;		/* go to the next pass */
	}
}
void set_to_0(int array[], int last_value) 
{/************************************************/
    int j;
    for (j = 0; j < last_value; j++)
	array[j] = 0;
}
void print_array(int array[], int array_length) 
{/********************************************/
    int index;
    for (index = 0; index < array_length; index++)
	printf("%3d ", array[index]);
    printf("\n");
}


