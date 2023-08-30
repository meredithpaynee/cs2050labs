#include "lab2.h"

int makeArray(int ** array, int size)
{
    //initalize array and allocate a spot in memory for it
    int * a;
    a = malloc(size * sizeof(int));
    //set array to point to the address of a
    *array = a;
    
    //test for null
    if(a == NULL)
    {
        return 1;
    }

    return 0;
}

void initArray(int *array, int size)
{
    //test for null
    if (array == NULL)
    {
        printf("ERROR");
    }

    //initalize every value in the array to 0
    for (int i = 0; i < size; i++)
    {
        *(array + i) = 0;
    }
}

int multiplyNegative(int *array, int size, int multiplicand)
{
    //test for null
    if (array == NULL)
    {
        return 1;
    }
    //set counter variable for number of negatives 
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        //test if the number is negative
        if(array[i] < 0)
        {
            //multiply it by the multiplicand and add to the counter
            array[i] *= multiplicand;
            counter++;        
        }
    }

    //returns number of negatives
    return counter;
}

void freeArray(int **array)
{
    //frees the pointer after malloc is called
    free(array);
}
