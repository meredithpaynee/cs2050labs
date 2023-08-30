#include <stdio.h>
#include <stdlib.h>

typedef struct employee{
    int ssn;
    int id;
    float salary;
    struct employee * left;
    struct employee * right;
}Employee;

typedef struct{
    Employee * root;
    int size;
    int ec;
}EmpDatabaseInfo;

typedef struct{
    EmpDatabaseInfo * info;
}EmpDatabase;

EmpDatabase createSearchableEmployeeDB();
EmpDatabase insertEmp(Employee *, EmpDatabase);
int countEmpsInSalaryRange(int min, int max, EmpDatabase);
void freeEmpDatabase(EmpDatabase);
int getErrorCode(EmpDatabase);