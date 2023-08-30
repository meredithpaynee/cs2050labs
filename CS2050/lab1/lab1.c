#include "lab1.h"

int getAverage(int array[], int size, float *result)
{
    
    float sum = 0;
    float tempResult = 0;

    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
        
    tempResult = sum/size;
    *result = tempResult;

    if (*(result) == sum/size)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int sumEven(int array[], int size, int *result)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if(array[i] % 2 == 0)
        {
            sum += array[i];
        }
    }

    *result = sum;

    if (*(result) == sum)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
