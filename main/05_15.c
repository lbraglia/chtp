#include <stdio.h>
#include <math.h>

double hypotenuse(double side_a, double side_b);

int main()
{/*******/

    printf("hypo 3, 4: %.2lf\n", hypotenuse(3, 4));
    printf("hypo 5, 12: %.2lf\n", hypotenuse(5, 12));
    printf("hypo 8, 15: %.2lf\n", hypotenuse(8, 15));

    return 0;
}


double hypotenuse(double side_a, double side_b)
{/********************************************/

    return sqrt(pow(side_a, 2) + pow(side_b, 2));
}
