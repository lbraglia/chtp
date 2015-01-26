/* 
   11_16.c
 */

#include <stdio.h>


int main(void)
{

    FILE *fp;

    fp = fopen("datasize.dat", "w");

    fprintf(fp, "%-20s%4s\n", "Data type", "Size");
    fprintf(fp, "%-20s%4lu\n", "char", sizeof(char));
    fprintf(fp, "%-20s%4lu\n", "unsigned char", sizeof(unsigned char));
    fprintf(fp, "%-20s%4lu\n", "short int", sizeof(short int));
    fprintf(fp, "%-20s%4lu\n", "unsigned short int",
	    sizeof(unsigned short int));
    fprintf(fp, "%-20s%4lu\n", "int", sizeof(int));
    fprintf(fp, "%-20s%4lu\n", "unsigned int", sizeof(unsigned int));
    fprintf(fp, "%-20s%4lu\n", "long int", sizeof(long int));
    fprintf(fp, "%-20s%4lu\n", "unsigned long int",
	    sizeof(unsigned long int));
    fprintf(fp, "%-20s%4lu\n", "float", sizeof(float));
    fprintf(fp, "%-20s%4lu\n", "double", sizeof(double));
    fprintf(fp, "%-20s%4lu\n", "long double", sizeof(long double));
    fclose(fp);
    return 0;

}
