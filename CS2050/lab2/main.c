#include "lab2.h"

int main(void)
{
    int a[] = {8,4,2,5,-4,-6,-9,-3};
    int b[8];
    int ** ptr;
    printf("Successful? %d", makeArray(ptr, 8));

    initArray(b, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d\n", b[i]);
    }
    printf("\n\n");

    printf("number of negatives: %d\n", multiplyNegative(a, 8, 6));
    for (int i = 0; i < 8; i++)
    {
        printf("%d\n", a[i]);
    }

    freeArray(a);
    freeArray(b);
}