/* 
   04_28
 */

#include <stdio.h>

int main(void) {

   int type;
   int hours_worked;
   int items_selled;
   float salary;
   float hourly_wages;
   float weekly_sales;
   float item_price;

   printf("Enter worker type (-1 to exit): ");
   scanf("%d", &type);

   while(type != -1) {

      switch(type) {

      case 1:
	 printf("Enter manager week salary: ");
	 scanf("%f", &salary);
	 printf("Week salary: %.2f\n\n", salary);
	 break;

      case 2:
	 printf("Enter hourly wages: ");
	 scanf("%f", &hourly_wages);
	 printf("Enter hours worked: ");
	 scanf("%d", &hours_worked);
	 salary = (hours_worked>40)?
	    (40.0 * hourly_wages) + (hours_worked -40)*(1.5*hourly_wages) :
	    hours_worked*hourly_wages;
	 printf("Week salary: %.2f\n\n", salary);
	 break;

      case 3:
	 printf("Enter weekly sales: ");
	 scanf("%f", &weekly_sales);
	 printf("Week salary: %.2f\n\n", 250.0 + 0.057*weekly_sales );
	 break;

      case 4:
	 printf("Enter items selled: ");
	 scanf("%d", &items_selled);
	 printf("Enter item price: ");
	 scanf("%f", &item_price);
	 printf("Week salary: %.2f\n\n", items_selled * item_price );
	 break;

      default:
	 printf("Incorrect type\n\n");
	 break;

      }
      
      salary = 0.0;
      printf("Enter worker type (-1 to exit): ");
      scanf("%d", &type);

   }

   return 0;


}
