#include <stdio.h>

int main()
{
	int side, curcol, currow = 1;
	int side_min = 1;
	int side_max = 20;
	
	printf("Insert the (integer between %d and %d) square side : ", side_min, side_max);
	scanf("%d", &side);
	
	if(side < side_min )
		printf("Side must be > %d\n", side_min);
	
	else if(side <= side_max){
		
		while (currow <= side) {
			
			curcol = 1;
			
			while (curcol <= side) {
				printf("*");
				curcol++;
			}
			
			printf("\n");
			currow++;
		}
	}else
		printf("side must be <= %d\n", side_max);

	return 0;
}
