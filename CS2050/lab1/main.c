#include "lab1.h"
#include <stdio.h>

int main()
{
    int array[] = {18,3,4,7,2,9,3,4,8};
    float average;
    int sum;
    int test1 = getAverage(array, 9, &average);
    int test2 = sumEven(array, 10, &sum);
    printf("Test 1: %d\n", test1);
    printf("Test 2: %d\n", test2);
    printf("Average of Array: %f\n", average);
    printf("Sum Value = %d\n", sum);
}
