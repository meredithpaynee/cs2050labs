#include <stdio.h>
#include <stdlib.h>

typedef struct employee{
    int ssn;
    int id;
    float salary;
}Employee;

typedef struct{
    int * ssnArray;
    int * idArray;
    int * salaryArray;

    int size;
    int ec;
}EmpDatabaseInfo;

typedef struct{
    EmpDatabaseInfo * info;
}EmpDatabase;


EmpDatabase createSearchableEmployeeDB(Employee **, int);
Employee * findEmpBySSN(int, EmpDatabase);
Employee * findEmpByID(int, EmpDatabase);
void freeEmpDatabase(EmpDatabase);
int getErrorCode(EmpDatabase);
int countEmpsInSalaryRange(int min, int max, EmpDatabase);