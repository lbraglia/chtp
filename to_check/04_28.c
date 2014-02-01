#include<stdio.h>

int main(void)
{
	float pay, tpay, salary, sales, pitem, hours, items;
	int paycode;
	printf("Enter employee paycode (or 999 to exit):\n");
	scanf("%d", &paycode);
	while(paycode != 999)
	{
		switch(paycode)
		{
			case 1:
				printf("Employee's weekly salary: ");
				scanf("%f", &salary);
				printf("Employee is to be paid %.2f\n\n", salary);
				break;
			case 2:
				printf("Employee's hourly pay: ");
				scanf("%f", &pay);
				printf("Hours worked: ");
				scanf("%f", &hours);
				if(hours>=40) 
				{
					tpay = ( (hours - 40) * 1.5 * pay ) + ( pay * 40 );
				}
				else
				{
					tpay = hours * pay;
				}
				printf("Employee is to be paid %.2f\n\n", tpay);
				break;
			case 3: 
				printf("Weekly sales: ");
				scanf("%f", &sales);
				printf("Employee is to be paid %.2f\n\n", 250 + ( ( sales / 100 ) * 5.7 ) );
				break;
			case 4:
				printf("Items produced: ");
				scanf("%f", &items);
				printf("Pay per item: ");
				scanf("%f", &pitem);
				printf("Employee to be paid %.2f\n\n", items * pitem);
				break;
			case ' ':
			case '\n':
			case '\t':
				break;
			default:
				printf("Paycode not recognised.\n\n");
		}
	printf("Enter employee paycode (or 999 to exit):\n");
	scanf("%d", &paycode);
	}
	return 0;
}	
