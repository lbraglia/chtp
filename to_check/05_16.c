#include<stdio.h>

long int integerPower( long int base, long int exponent);

int main()
{
    long int x,y,z;
    
    printf("Please input your base: ");
    scanf("%ld", &x);
    printf("Please input your power: ");
    scanf("%ld", &y);
    
    z = integerPower(x,y);
    
    printf("%ld\n\n", z);
    
    
    return 0;
}

long int integerPower( long int base, long int exponent)
{
    long int a = base;
    long int x;
    
    for ( x=1; x<=exponent-1 ; x++)
    {
        a *=base;
    }

    return a;
}
   
    
  
    
