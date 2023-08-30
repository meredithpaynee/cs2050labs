#include "prelab9.h"

//function to create employee (basically a node)
Employee * createEmployee (int ssn, int id)
{
    Employee * n = malloc(sizeof(Employee));

    if (n)
    {
        n->ssn = ssn;
        n->id = id;
        n->next = NULL;
        n->position = 0;
    }

    return n;
}

//function to that returns the employee in the middle of the linked list
Employee * findMid(EmpDatabase base, int first, int last)
{
    Employee * ptr = base.info->head;

    if(ptr)
    {
        base.info->ec = 0;
        for (int i = 1; i <= ((first+last)/2); i++)
        {
            ptr = ptr->next;
        }
        return ptr;
    }

    base.info->ec = 1;
    return NULL; 
}

//binary search for SSN, called in the provided function
Employee * binarySSNSearch(EmpDatabase base, int first, int last, int ssn)
{
    Employee * emp = findMid(base, first, last);
    int mid = emp->position;

    if (first == last)
    {
        return NULL;
    }

    if (emp)
    {
        base.info->ec = 0;
        if(ssn < emp->ssn) //fix
        {
            return(binarySSNSearch(base, first, mid, ssn));
        }
        else if (ssn > emp->ssn) //fix
        {
            return(binarySSNSearch(base, mid + 1, last, ssn));
        }

        return emp;
    }
    else
    {
        base.info->ec = 1;
        return NULL;
    }
}

Employee * binaryIDSearch(EmpDatabase base, int first, int last, int id)
{
    Employee * emp = findMid(base, first, last);
    int mid = emp->position;

    if (first == last)
    {
        return NULL;
    }

    if (emp)
    {
        if(id < emp->id) //fix
        {
            return(binaryIDSearch(base, first, mid, id));
        }
        else if (id > emp->id) //fix
        {
            return(binaryIDSearch(base, mid + 1, last, id));
        }

        return emp;
    }
    else
    {
        base.info->ec = 1;
        return NULL;
    }
}


EmpDatabase createSearchableEmployeeDB(Employee ** a, int n)
{
    //create database and initialize its pointer
    EmpDatabase base;
    base.info = malloc(sizeof(EmpDatabaseInfo));

    if (base.info)
    {
        Employee * first = createEmployee(a[1]->ssn, a[1]->id);
        first->position = 1;
        base.info->head = first;
        base.info->listLength = n;

        for (int i = 1; i <= n; i++)
        {
            Employee * emp = createEmployee(a[i+1]->ssn, a[i+1]->id);
            a[i]->next = emp;
            emp->position = i+1;
            base.info->listLength++;
        }
    }
    else
    {
        base.info->ec = 1;
    }   

    return base;
}

Employee * findEmpBySSN(int ssn, EmpDatabase base)
{
    //test for empty list
    if (base.info->head == NULL)
    {
        return NULL;
    }

    Employee * ptr = binarySSNSearch(base, 1, base.info->listLength, ssn);

    return ptr;    
}

Employee * findEmpByID(int id, EmpDatabase base)
{
    //test for empty list
    if (base.info->head == NULL)
    {
        return NULL;
    }

    Employee * ptr = binaryIDSearch(base, 1, base.info->listLength, id);

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
    Employee * ptr, * temp;
    for(ptr = base.info->head; ptr != NULL; ptr = ptr->next)
    {
        temp = ptr->next;
        free(ptr);
        ptr = temp;
        
    }
}

int getErrorCode(EmpDatabase base)
{
    return base.info->ec;
}



int main(void)
{
    printf("hi\n");
}

void bubbleSort(Employee * info, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if()
        }
    }
}

int * createSSNArray(EmpDatabase base)
{
    int array[base.info->listLength];
    Employee * ptr;
    int i = 1;

    (ptr = base.info->head; ptr != NULL; ptr = ptr->next)
    {
        array[i] = ptr->ssn;
        i++
    }

    return array;
}

int * createIDArray(EmpDatabase base)
{
    int array[base.info->listLength];
    Employee * ptr;
    int i = 1;

    (ptr = base.info->head; ptr != NULL; ptr = ptr->next)
    {
        array[i] = ptr->id;
        i++
    }

    return array;
}

/*For this prelab you will need to implement some functions that are specialized for use with Employee
objects/structs, each of which has an integer member "SSN" for Social Security Number and integer "ID"
for employee identification number. For the first function, the user will pass an array of pointers to N
employee structs, along with the integer N, and the function will return a "database" that can be
efficiently searched (returns NULL if it can’t be created). The second function permits a pointer to an
employee record to be efficiently retrieved based on a given SSN. The third function does the same
except it efficiently retrieves based on a given employee ID. The last function is called when the user is
finished with the database

The requirement that the two search functions must "efficiently" retrieve the requested employee
record is to be interpreted as doing so in O(log(N)) time. That means you'll have to create at least one
array with pointers to employee records that you have sorted by a particular member so that you can
exploit the efficiency of binary search. If no employee record is found that satisfies a request, then NULL
is returned.
You’re already familiar with the use of a getErrorCode function, but for this prelab try to think of all the
kinds of error/warning conditions that might be of value to a user. For example, the user might be
interested knowing whether an invalid SSN or employee ID was passed to a function.*/