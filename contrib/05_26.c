#include<stdio.h>

int perfect(int x);

int main()
{

    int a,b,c;

    printf("\nPlease enter your range of number: ");
    scanf("%d", &a);
    printf("The list of perfect number between 1 and  %d is\n",a);

    for(c=1 ; c<=a ; c++ )
    {

        b=perfect(c);
        if ( b == c)
        {
            printf("%d\n",c);
        }

    }

    return 0;
}

int perfect( int x)
{
    int i,sum =0;

    for( i=1 ; i<x ; i++)
    {
       if(x%i == 0)
       sum +=i;
    }
    return sum;
}
