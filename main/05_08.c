#include <stdio.h>
#include <math.h>

int main(void)
{
    double x;

    x = fabs(7.5);
    printf("fabs(7.5) = %.1f\n", x);
    x = floor(7.5);
    printf("floor(7.5) = %.1f\n", x);
    x = fabs(0.0);
    printf("fabs(0.0) = %.1f\n", x);
    x = ceil(0.0);
    printf("ceil(0.0) = %.1f\n", x);
    x = fabs(-6.4);
    printf("fabs(-6.4) = %.1f\n", x);
    x = ceil(-6.4);
    printf("ceil(-6.4) = %.1f\n", x);
    x = ceil(-fabs(-8 + floor(-5.5)));
    printf("ceil( -fabs (-8 + floor(-5.5))) = %.1f\n", x);

    return 0;
}
