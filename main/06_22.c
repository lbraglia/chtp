#include <stdio.h>

#define SELLERS 5
#define PRODUCTS 4


int main(void)
{/***********/

    void print_matrix(const float matrix[PRODUCTS][SELLERS],
		      int prods, int slrs);

    int sel_code;
    int prod_code;
    float sold;
    float sales[PRODUCTS][SELLERS] = { 0 };



    /* Enter the first sell-ticket: let's begin from seller
       code. If -1 exit */
    printf("Enter seller's code (-1 to exit): ");
    scanf("%d", &sel_code);

    while (sel_code != -1) {

	/* Get the product code */
	printf("Enter product code: ");
	scanf("%d", &prod_code);

	/* Get the sold */
	printf("Enter sold for seller %d, product %d: ",
	       sel_code, prod_code);
	scanf("%f", &sold);

	/* Update the sales matrix */
	sales[prod_code - 1][sel_code - 1] += sold;

	/* Restart the while */
	printf("Enter sellers code (-1 to exit): ");
	scanf("%d", &sel_code);




    }

    print_matrix(sales, PRODUCTS, SELLERS);

    return 0;
}



void print_matrix(const float matrix[PRODUCTS][SELLERS],
		  int prods, int slrs)
{/*******************************************************/

    int i, j;			/* indexes for rows and cols */
    float rowsum = 0;
    float colsum = 0;
    float totalsum = 0;

    printf("\n\n");

    printf("[P\\F]\t[   1]\t[   2]\t[   3]\t[   4]\t[   5]\t[ Tot ]\n");

    for (i = 0; i < prods; i++) {


	for (j = 0; j < slrs; j++) {
	    /* print the row header */
	    if (j == 0)
		printf("[%3d]\t", i + 1);
	    /* print the row */
	    printf("[%4.2f]\t", matrix[i][j]);
	    /* print the row sums */
	    if (j == slrs - 1) {
		for (j = 0; j < slrs; j++)
		    rowsum += matrix[i][j];
		printf("[%4.2f]", rowsum);
		/* restart to 0 */
		rowsum = 0;
	    }


	}
	printf("\n");

    }


    /* colums sum */
    printf("[Tot]\t");

    for (j = 0; j < slrs; j++) {

	for (i = 0; i < prods; i++)
	    colsum += matrix[i][j];
	printf("[%.2f]\t", colsum);
	totalsum += colsum;
	colsum = 0;
    }

    printf("[%.2f]", totalsum);

    printf("\n\n");

}
