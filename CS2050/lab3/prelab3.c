#include "prelab3.h"

void freeArray(void * a)
{
    char * ptr = a;
    //test for null
    if (a != NULL)
    {
        ptr--;
        //free a
        free(ptr);
    }
}

void * createArray(int length, int dataTypeSize)
{
    //allocate room for a
    int * a = malloc((length * dataTypeSize) + dataTypeSize);

    //test for null
    if (a != NULL)
    {
        //initializing a[0] to the length then making it a[-1] to be accessible
        a[0] = length;
        a++;
    }

    //return an array
    return a;
}

int getArraySize(void * a)
{
    //pointer for analyzing array
    int * ptr = a;

    //test for null
    if (a == NULL)
    {
        printf("ERROR!\n");
    }

    //returns size set in createArray()
    return ptr[-1];
}