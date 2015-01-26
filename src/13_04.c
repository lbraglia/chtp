/* 
   13_04: sphere volume with macro
 */
#include <stdio.h>

#define PI 3.14159
#define SPHERE_VOLUME(r) ( ( 4.0 / 3 ) * PI * (r) * (r) * (r)  )

int main(void)
{

    int r = 0;

    printf("%6s%10s\n", "Radius", "Volume");
    for (r = 1; r <= 10; r++) {
	printf("%6d%10.2f\n", r, SPHERE_VOLUME(r));
    }

    return 0;
}
