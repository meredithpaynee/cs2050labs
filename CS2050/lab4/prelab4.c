#include "prelab4.h"


Employee * readEmployeeArray(FILE * fp)
{
    fp = fopen("text.txt", "r");
    int size = 0;
    fscanf(fp, "%d", &size);
    
    int * a = malloc(size * sizeof(Employee) + sizeof(int));

    a[0] = size;
    a++;

    for (int i = 0; i < size; i++)
    {
        //intitalize with employees data
        fscanf(fp, "%d", &((Employee*)a)[i].empID);
        fscanf(fp, "%d", &((Employee*)a)[i].jobType);
        fscanf(fp, "%f", &((Employee*)a)[i].salary);
    }
    fclose(fp);

    return (Employee*)a;
}

int getArraySize(void * a)
{
    return ((int *)a)[-1];
}

void freeArray(void * a)
{
    a--;
    free(((int *)a));
}

Employee * getEmployeeByID(Employee * a, int empID)
{
    Employee * ePtr;

    for (int i = 0; i < getArraySize(a); i++)
    {
        if(a[i].empID == empID)
        {
            ePtr = &a[i];
        }
    }

    if (ePtr == NULL)
    {
        printf("***NO EMPLOYEE WITH THAT ID NUMBER***\n");
    }
    
    return ePtr;
}


int setEmpSalary (Employee * a, int empID, float salary)
{
    //go through the array, once the empID matches set the employees salary to the value given in the parameter
    for (int i = 0; i < getArraySize(a); i++)
    {
        if (a[i].empID == empID)
        {
            a[i].salary = salary;
        }
    }


    if(!salary)
        return 1;
    else 
        return 0;
}

int getEmpSalary (Employee * a, int empID, float * salary)
{
    //go through the array and find the right employee, then return their salary value
    for (int i = 0; i < getArraySize(a); i++)
    {
        if (a[i].empID == empID)
        {
            *salary = a[i].salary;
        }
    }

    if(!salary)
        return 1;
    else 
        return 0;
    
}

int setEmpJobType (Employee * a, int empID, int job)
{
    for (int i = 0; i < getArraySize(a); i++)
    {
        if (a[i].empID == empID)
        {
            a[i].jobType = job;
        }
    }
    
    if(!job)
        return 1;
    else 
        return 0;
}

int getEmpJobType (Employee * a, int empID, int * job)
{
    //go through the array and find the right employee, then return their job type
    for (int i = 0; i < getArraySize(a); i++)
    {
        if (a[i].empID == empID)
        {
            *job = a[i].jobType;
        }
    }
    
    if(!job)
        return 1;
    else 
        return 0;
}