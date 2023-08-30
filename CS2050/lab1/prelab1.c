#include <stdio.h>
#include "prelab1.h"

int getArrayInfo(int * a, int n, int *rmax, int*rmin)
{  
    //setting variables
	int max = a[0];
	int min = a[0];
	int num = 0;  
    int count = 0;
	
    //big for loop to go through the array once
	for (int i = 0; i < n; i++)
    {
        //if the value is less than the minimum, reset min to the value
		if (a[i] < min)
		{
			min = a[i];
		}
        //if the value is more than the maximum, reset max to the value
		else if (a[i] > max)
		{
			max = a[i];
		}

        //nested for loop to go through the array again every time
        for (int j = 0; j < n; j++)
        {
            //if the array i value is equal to array j, increase count to note it
            if(a[i] == a[j])
            { 
                count++;
            }
        }
        //if the count is less than or equal to one (one because its compared to itself),
        //increase the number because that means it's unique within the array
        if(count <= 1)
        {
            num++;
        }
        //reset the count for the new array i value
        count = 0;
	}
    //passes max and min by reference since function can't return more than one value
	*rmax = max;
	*rmin = min;
	
    //returns number of unique values
	return num;
}
