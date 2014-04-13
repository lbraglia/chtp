#include <stdio.h>
#include <math.h>

/* to be compiled with "gcc -lm 05_09.c" */

double calculateCharges(float hours);

int main(void)
{


    float car_a_hours, car_b_hours, car_c_hours, tothours;
    float car_a_charge, car_b_charge, car_c_charge, totcharge;

    printf("\n\n");

    printf("enter car #1 parking hours: ");
    scanf("%f", &car_a_hours);
    printf("enter car #2 parking hours: ");
    scanf("%f", &car_b_hours);
    printf("enter car #3 parking hours: ");
    scanf("%f", &car_c_hours);

    tothours = car_a_hours + car_b_hours + car_c_hours;

    car_a_charge = calculateCharges(car_a_hours);
    car_b_charge = calculateCharges(car_b_hours);
    car_c_charge = calculateCharges(car_c_hours);

    totcharge = car_a_charge + car_b_charge + car_c_charge;

    printf("\n\n");

    printf("Car\tHours\tCharge\n");
    printf("%d\t%5.1f\t%6.2f\n", 1, car_a_hours, car_a_charge);
    printf("%d\t%5.1f\t%6.2f\n", 2, car_b_hours, car_b_charge);
    printf("%d\t%5.1f\t%6.2f\n", 3, car_c_hours, car_c_charge);
    printf("TOTAL\t%5.1f\t%6.2f\n", tothours, totcharge);

    printf("\n\n");

    return 0;

}


double calculateCharges(float hours)
{
    if ((hours - 3.0) <= 0)
	return 2.0;
    else if ((hours == 24.0))
	return 10;
    else
	return (ceil(hours) - 3) * 0.5 + 2;
}
