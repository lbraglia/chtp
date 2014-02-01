// program of encryption.c : main project file.

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char *argv[])
{
	int number,x;
	int digit1,ert1,ert2;
	int digit2;
	int digit3;
	int digit4,temp;
	number=0;
	digit1=-1;
	digit2=-1;
	digit3=-1;
	digit4=-1;
	x=1;
	temp=675;
	printf("Enter number to encrypt....\n");
	scanf("%d",&number);

	while(x<=10000)
	{ert1=10*x;
	ert2=ert1/10;
		temp=((number%ert1)-(number%ert2))/ert2;
		x*=10;
		temp+=7;
		temp=temp%10;
		if(digit4 == -1)
			digit4=temp;		
		else
			if (digit3== -1)
				digit3=temp;
			else                                                                                  /*i dont use switch as one that has read the book shouldnt have learnt it by then */
				if (digit2 == -1)
					digit2=temp;
				else 
					if (digit1 == -1)
						digit1=temp;
	}
	number=0;
	number=1000*digit3+100*digit4+10*digit1+digit2;
	printf("The encrypted number is....%d\n",number);
  system("PAUSE");
    return 0;
}
