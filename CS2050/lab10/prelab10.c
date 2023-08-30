#include "prelab10.h"

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int * a, int first, int last)
{
    if (first < last)
    {
        //returns the partition point and swaps the elements, recursive call so it runs until sorted
        int p = partition(a, first, last);
        quickSort(a, first, p - 1);
        quickSort(a, p + 1, last);
    }
}

int partition(int * a, int first, int last)
{
    //pick last element in the array as the pivot point and create 
    int pivot = a[last];

    int b = first - 1;

    //go through the array and compare a[i] to the pivot
    for(int i = first; i < last; i++)
    {
        if(a[i] <= pivot)
        {
            //if the element is smaller than the pivot swap it with a[b]
            b++;
            swap(&a[b], &a[i]);
        }
    }

    //final swap of pivot element and the element at b
    swap(&a[b + 1], &a[last]);

    //this returns the partition point
    return (b + 1);
}

int binaryIDSearch(EmpDatabase base, int first, int last, int id)
{
    int mid = (first + last)/2;
    
    if (first == last)
    {
        return -1;
    }

    if(base.info->idArray[mid] < id) //fix
    {
        return(binaryIDSearch(base, mid + 1, last, id));
    }
    else if (base.info->idArray[mid] > id) //fix
    {
        return(binaryIDSearch(base, first, mid - 1, id));
    }

    return mid;
}

int binarySSNSearch(EmpDatabase base, int first, int last, int ssn)
{
    int mid = (first + last)/2;
    
    if (first == last)
    {
        return -1;
    }

    if(base.info->ssnArray[mid] < ssn) //fix
    {
        return(binarySSNSearch(base, mid + 1, last, ssn));
    }
    else if (base.info->ssnArray[mid] > ssn) //fix
    {
        return(binarySSNSearch(base, first, mid - 1, ssn));
    }

    return mid;
}

int binarySalarySearch(EmpDatabase base, int first, int last, int salary)
{
    int mid = (first + last)/2;
    
    if (first == last)
    {
        return -1;
    }

    if(base.info->salaryArray[mid] < salary) //fix
    {
        return(binarySalarySearch(base, mid + 1, last, salary));
    }
    else if (base.info->salaryArray[mid] > salary) //fix
    {
        return(binarySalarySearch(base, first, mid - 1, salary));
    }

    return mid;
}

//fix this to have O(N*log(N)) complexity
EmpDatabase createSearchableEmployeeDB(Employee ** a, int n)
{
    //create database and initialize its pointer
    EmpDatabase base;
    base.info = malloc(sizeof(EmpDatabaseInfo));   

    if(base.info)
    {
        for(int i = 0; i < n; i++)
        {
            base.info->ssnArray[i] = a[i]->ssn;
            base.info->idArray[i] = a[i]->id;
            base.info->salaryArray[i] = a[i]->salary;
        }

        quickSort(base.info->ssnArray, 0, n - 1);
        quickSort(base.info->idArray, 0, n - 1);
        quickSort(base.info->salaryArray, 0, n - 1);        
    
        base.info->size = n;
        base.info->ec = 0;
    }

    return base;
}


Employee * findEmpBySSN(int ssn, EmpDatabase base)
{
    //test for empty list
    if (base.info->ssnArray == NULL)
    {
        return NULL;
    }
    
    int index = binarySSNSearch(base, 0, base.info->size, ssn);

    Employee * ptr = base.info->ssnArray[index];

    if(ptr)
    {
        return ptr;
    }
    else 
    {
        base.info->ec = 1;
        return NULL;
    } 
}

Employee * findEmpByID(int id, EmpDatabase base)
{
    //test for empty list
    if (base.info->idArray == NULL)
    {
        return NULL;
    }

    int index = binaryIDSearch(base, 0, base.info->size, id);

    Employee * ptr = base.info->idArray[index];

    if(ptr)
    {
        return ptr;
    }
    else 
    {
        base.info->ec = 1;
        return NULL;
    }
}

void freeEmpDatabase(EmpDatabase base)
{
    free(base.info);
}

int getErrorCode(EmpDatabase base)
{
    return base.info->ec;
}

//find index of smallest and largest key through binary search. Subract the two numbers
int countEmpsInSalaryRange(int min, int max, EmpDatabase base)
{
    int small = binarySalarySearch(base, 0, base.info->size, min);
    int large = binarySalarySearch(base, 0, base.info->size, max);

    return large - small;
}
/*The return value is the number of employees with salaries greater than min and less than max. The
function is required to have O(log(n)) complexity, where n is the size of the database. In addition, the
function createSearchableEmployeeDB is required to have O(n*log(n)) or expected O(n*log(n)) time
complexity.
I’ve left some details unspecified, so it’s up to you to make and document your specific design decisions.*/


int main(void)
{
    printf("hi\n");
}