#include <stdio.h>
#include <stdlib.h>

typedef struct employee{
    int ssn;
    int id;
    struct employee * next;
    int position;
}Employee;

typedef struct{
    Employee * head, * mid;
    int listLength;
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