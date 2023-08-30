#include "lab4.h"

void * makeArray(int arraySize, int elementSize)
{
    //initialize a pointer
    void * ptr; 
    //create an array and allocate the memory for it (int so the first value can be stored)
    int * a = malloc(arraySize * elementSize + sizeof(int));
    //set a[0] to arraySize
    a[0] = arraySize;
    //increment array to make a[0] -> a[-1]
    a++;

    //set the pointer equal to a (casted to be an InventoryItem* array)
    ptr = ((InventoryItem *)a);

    //error tests
    if (a)
    {
        return ptr;
    }
    else 
    {
        return NULL;
    }
}

int getSize(void *array)
{
    //return the array casted to int*
    return ((int *)array)[-1];
}

int countGreaterID(InventoryItem *items, int minID)
{
    //create variable for count 
    int count = 0;

    //increment through the array
    for (int i = 0; i < getSize(items); i++)
    {
        //test for ID value
        if(items[i].ID >= minID)
        {
            //add one of the items id is equal to or greater than minID
            count++;
        }
    }

    //return the count
    return count;
}

void freeArray(void *array)
{
    //make the array point back to a[-1] and free the array casted to int
    free(((int *)array) - 1);
}