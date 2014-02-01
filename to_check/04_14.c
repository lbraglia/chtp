/* CALCULO DEL FACTORIAL DE UN NUMERO */

#include <stdio.h>

main()
{
	long factorial; /* long no supera los 2 mil millones, por eso 13! lo calcula mal*/
	int  number, counter = 1, i;  /* LAS VARIABLES SIRVEN PARA LOS DOS MODOS DE SOLUCIÓN */

	printf("NUMBER\tFACTORIAL\n\n:");

	/* PRIMER FORMA CON FOR  */

	for (i = 1; i <= 12; i += 1){
		number = i;
		factorial = i;
		while (number > 1) {
			factorial = factorial * (number - 1);
			--number;}
		printf("%d\t%d\n", i, factorial);


		}
	
	

/* SEGUNDA MANERA CON WHILE  */
	
	

/*while (counter <= 12) {
		number = counter;
		factorial = number;
		while (number > 1) {
			
			factorial = factorial * (number - 1);	
			--number;
			
			}
	
				
		printf("%d\t%d\n", counter, factorial);
		counter++;
		}*/
	
	return 0;

}
