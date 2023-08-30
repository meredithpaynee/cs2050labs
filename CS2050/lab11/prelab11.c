#include "prelab11.h"

//simple binary search for
int getCount(Employee * root, int maxSalary, int minSalary)
{
    if(root == NULL)
    {
        return 0;
    }

    if (root->salary <= maxSalary && root->salary >= minSalary)
    {
        return 1 + getCount(root->left, maxSalary, minSalary) + getCount(root->right, maxSalary, minSalary);
    }
    else if(root->salary < minSalary)
    {
        return getCount(root->right, maxSalary, minSalary);
    }
    else
    {
        return getCount(root->left, maxSalary, minSalary);
    }
}

//helper function for inserting leaf
Employee * insertLeaf(Employee * top, Employee * leaf)
{
    if (top == NULL)
    {
        top = leaf;
        return top;
    }

    if (leaf->salary < top->salary)
    {
        return insertLeaf(top->left, leaf);
    }
    else
    {
        return insertLeaf(top->left, leaf);
    }
}

EmpDatabase createSearchableEmployeeDB()
{
    //create database and initialize its pointer
    EmpDatabase base;
    base.info = malloc(sizeof(EmpDatabaseInfo)); 

    if (base.info)
    {
        base.info->size = 0;
        base.info->ec = 0;
        base.info->root = NULL;
    }
    return base;
}

/*Your insert function will just use the simple BST insertion algorithm, so it cant guarantee O(log(N))
complexity.*/
EmpDatabase insertEmp(Employee * leaf, EmpDatabase base)
{
    insertLeaf(base.info->root, leaf);

    base.info->size++;
    return base;
}

int countEmpsInSalaryRange(int min, int max, EmpDatabase base)
{
    int count = getCount(base.info->root, max, min);

    return count;
}

void freeEmpDatabase(EmpDatabase base)
{
    free(base.info);
}

int getErrorCode(EmpDatabase base)
{
    return base.info->ec;
}

int main(void)
{
    printf("hi\n");
}
