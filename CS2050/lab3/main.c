#include "lab3.h"


int main(void)
{
    char * a = strAlloc(8);
    char * b = strAlloc(15);
    int sizeA = strLen(a);
    int sizeB = strLen(b);
    char p = 'a';

    for (int i = 0; i < sizeA; i++)
    {
        a[i] = p;
        p++;
    }

    printf("Size a: %d\n", sizeA);
    printf("Size b: %d\n", sizeB);
    
    strCpy(a,b);

    for (int i = 0; i < sizeA; i++)
    {
        printf("a[%d] = '%c'\n", i, a[i]);
    }

    for (int i = 0; i < sizeB; i++)
    {
        printf("b[%d] = '%c'\n", i, b[i]);
    }

    printf("\nSize equal? %d\n", strRev(a,b));

    for (int i = 0; i < sizeA; i++)
    {
        printf("a[%d] = '%c'\n", i, a[i]);
    }

    for (int i = 0; i < sizeB; i++)
    {
        printf("b[%d] = '%c'\n", i, b[i]);
    }
    

    strFree(a);
    strFree(b);

    //printf("Size: %d\n", size);
}