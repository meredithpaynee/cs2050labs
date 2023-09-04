#include "lab3.h"


char * strAlloc(int size)
{
    //create array and allocate the size (with room for the size)
    int * a = malloc((size * sizeof(char)) + sizeof(char));

    //null nest
    if (a)
    {
        //makes a[0] the size of the array
        *array = size;
        //move the array (or the pointer to the array) up one
        a++;
        return (char *)a;
    }
    else 
    {
        return NULL;
    }
}

int strLen(char *str)
{
    //pointer to the array str
    int * ptr = (int *)str;

    //null test
    if (str == NULL)
    {
        return 0;
    }
    else
    {
        //pointer is set to str, so it points to str[0]. 
        //Calling for it to move back one to where the size is stored
        return ptr[-1];
    }
}

void strCpy(char *source, char *dest)
{
    //for loop (source will always be longer)
    for (int i = 0; i < strLen(source); i++)
    {
        //sets dest at i to source at i
        dest[i] = source[i];
    }
}

int strRev(char *source, char *dest)
{
    //for loop running source backwards
    for (int i = 0; i < strLen(source); i--)
    {
        //sets dest equal to source starting from the end of source
        dest[i] = source[size - i - 1];
    }
    
    //return statements (if the two have the same length or not)
    if (strLen(source) == strLen(dest))
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}


void strFree(char *str)
{
    //pointer to array str
    int * ptr = (int *)str;
    //sets the ptr back to where size is stored
    ptr--;

    //frees ptr, thus freeing str
    free(ptr);
}
