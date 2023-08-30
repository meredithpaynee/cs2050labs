#include "stdio.h"

int numGreater(int * a, int size, int n)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (a[i] >= n)
        {
            count++;
        }
    }

    return count;
}