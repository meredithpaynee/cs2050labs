#include "prelab1.h"
#include <stdio.h>

int main()
{
    int array[] = {3,4,1,5,4,6,7,9,3,7,10};
    int rMin, rMax;
    int var = getArrayInfo(array, 11, &rMax, &rMin);
    printf("Number of Unique Values: %d\n", var);
    printf("Max Value = %d\n", rMax);
    printf("Min Value = %d\n", rMin);
}

gcc prelab1.c main.c -Wall -Werror