/* compile with -lm */
#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2);

int main()
{

    double x1;
    double y1;
    double x2;
    double y2;

    printf("Enter point 1 (x y): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter point 2 (x y): ");
    scanf("%lf %lf", &x2, &y2);

    printf("Distance is: %f\n", distance(x1, y1, x2, y2));
    return 0;
}


double distance(double x1, double y1, double x2, double y2)
{

    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

}
