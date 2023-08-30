#include "lab3.h"


char * strAlloc(int size)
{
    //create array and allocate the size (with room for the size)
    char * a = malloc((size * sizeof(char)) + sizeof(char));

    //null nest
    if (a != NULL)
    {
        //makes a[0] the size of the array
        a[0] = size;
        //move the array (or the pointer to the array) up one
        a++;
        return a;
    }
    else 
    {
        return NULL;
    }
}

int strLen(char *str)
{
    //pointer to the array str
    char * ptr = str;

    //null test
    if (str == NULL)
    {
        return 1;
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
    //counter for dest index
    int counter = 0;
    //for loop running source backwards
    for (int i = strLen(source); i > 0; i--)
    {
        //sets dest equal to source starting from the end of source
        dest[counter] = source[i - 1];
        //incrementing dest index
        counter++;
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
    char * ptr = str;
    //sets the ptr back to where size is stored
    ptr--;

    //frees ptr, thus freeing str
    free(ptr);
}
