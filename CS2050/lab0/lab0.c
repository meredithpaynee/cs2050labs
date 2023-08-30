#include "lab0.h"

/* REQUIRED CODE GOES HERE */

int countOccurrences(int size, int * a, int n)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if(a[i] == n)
        {
            count++;
        }
    }
    return count;
}
