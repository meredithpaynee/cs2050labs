#include <stdio.h>
#include <stdlib.h>

typedef struct{
        int empID, jobType;
        float salary;
    } Employee;


Employee * readEmployeeArray(FILE * fp);
int getArraySize(void * a);
void freeArray(void * a);
Employee * getEmployeeByID(Employee *, int empID);

int setEmpSalary (Employee * a, int empID, float salary);
int getEmpSalary (Employee * a, int empID, float * salary);
int setEmpJobType (Employee * a, int empID, int job);
int getEmpJobType (Employee * a, int empID, int * job);