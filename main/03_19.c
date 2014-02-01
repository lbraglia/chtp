#include <stdio.h>
/* Solution provided by Blackeye */

int main()
{
	float sales;

	printf( "Enter sales in dollars ( -1 to end ): " );
	scanf( "%f", &sales );

	while ( sales != -1 ) {
		printf( "Salary is: $%.2f\n\n", 200 + 0.09 * sales );
		printf( "Enter sales in dolllars ( -1 to end ): " );
		scanf( "%f", &sales );
	}

	return 0;
}
