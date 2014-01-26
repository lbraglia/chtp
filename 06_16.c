#include <stdio.h>

void print_matrix(int matrix[3][5]);

int main(void)
{

    int sales[3][5];
    int row, column;
    int order = 1;


    for (row = 0; row < 3; row++)
	for (column = 0; column < 5; column++)
	    sales[row][column] = order++;

    printf("\n");
    print_matrix(sales);
    printf("\n");



    return 0;
}





void print_matrix(int matrix[3][5])
{

    int row, col;

    for (row = 0; row < 3; row++) {
	for (col = 0; col < 5; col++)
	    printf("[%3d] ", matrix[row][col]);
	printf("\n");
    }
}
