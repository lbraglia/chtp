#include <stdio.h>

int main()
{

    int binary;

    int size = 1;
    int Next = 1;
    int mult = 10;

    int decimal = 0;
    int value = 1;
    int module = 10;

    int pos;    
    
    printf("Binary  -> ");
    scanf("%d", &binary);

    while (Next) {
	if (binary >= mult) {
	    size++;
	    mult *= 10;
	} else
	    Next = 0;
    }

    while (size--) {
	pos = (binary % module) / (module / 10);
	module *= 10;
	decimal += (pos >= 1 ? 1 : 0) * value;
	value *= 2;
    }

    printf("Decimal -> %d\n", decimal);

    return 0;
}
