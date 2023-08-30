#include "lab9.h"


//helper function to find the middle element
Flight * findMid(Flight * array, int first, int last)
{
    //pointer to the array
    Flight * ptr = array;

    if (first == last)
    {
        return NULL;
    }

    //go through half of the array and change the location the ptr var points to
    for (int i = 0; i <= ((first+last)/2); i++)
    {
        ptr++;
    }

    //return the element
    return ptr;
}

//helper function that creates the binary search algorithm to be called in searchFlights()
int binarySearch(Flight * query, Flight * array, int first, int last)
{
    //create mid element and mid index variables
    Flight * mid = findMid(array, first, last);
    int num = (first + last)/2;

    //error test
    if (first == last)
    {
        return -1;
    }

    //comparisons from query to mid and recursively call binary search
    //parameters of first and last change depending on the mid's relation to query
    if (query < mid)
    {
        return binarySearch(query, array, first, num);
    }
    else if (query > mid)
    {
        return binarySearch(query, array, num + 1, last);
    }
    return num;
}

void * makeArray(int arraySize, int elementSize)
{
    //create and allocate array
    int * array = malloc(arraySize * elementSize + sizeof(int));

    //check for malloc failure, if it works make arraySize a[0] and move the pointer location
    if (array)
    {
        *array = arraySize;
        array++;
    }

    return array;
}

//create pointer for accessing array[-1] and return the value
int getSize(void *array)
{
    int * a = array;
    return *(a - 1);
}

// O(log(n))
//call binarySearch (written above) and return the index it finds
int searchFlights(Flight *array, Flight *query)
{
    int index = binarySearch(query, array, 0, getSize(array));

    return index;
}

// O(1)
//compare each of the possible scenarios and return -1, 1, or 0 depending on the result
int compareFlights(Flight *a, Flight *b)
{
    int status; 

    //a's distance is less than b's
    if (a->distance < b->distance)
    {
        status = -1;
    }
    //a's distance is more than b's
    else if (a->distance > b->distance)
    {
        status = 1;
    }
    //a and b's distance are equal
    else 
    {
        status = 0;
    }

    return status;
}

//
void freeArray(void *array)
{
    //create pointer, move it to array[-1], and free the whole thing
    int * a = array;
    a--;
    free(a);
}