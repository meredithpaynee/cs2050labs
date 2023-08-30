#include <stdio.h>
#include <stdlib.h>


void freeFloatArray(float *(*array));

float * readFloatFileIntoArray(FILE * fptr, int * length);

void *createArray(int n, int dataTypeSize);