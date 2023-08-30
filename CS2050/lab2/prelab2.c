#include "prelab2.h"

void freeFloatArray(float *(*array))
{
    array = NULL;
    free(array);
}

void * createArray(int n, int dataTypeSize)
{
    int * a;
    a = malloc(n * dataTypeSize);
    ((int*)a)[0] = n;
    return ((int*)a) + 1;
}

float * readFloatFileIntoArray(FILE * fptr, int * length)
{
    *length = fgetc(fptr);
    float * a = createArray(*length, sizeof(float));

    if(a == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < *length; i++)
    {
        fscanf(fptr, "%f", &a[i]);
        //read float at i in file and store float into array[i]
        fptr++;
    }

    freeFloatArray(&a);

    return (void *)(a+1);

}

/*int * practiceArray(int * array, int length)
{
    int * a = NULL;
    a = malloc(length*sizeof(int));

    for (int i = 0; i < length; i++)
    {
        a[i] = array[i];
    }

    free(a);
    return a;
}*/