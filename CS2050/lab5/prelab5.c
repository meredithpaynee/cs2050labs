#include "prelab5.h"


List * createNode(int object)
{
    List * head = malloc(sizeof(List));

    if (head)
    {
        head->object = object;
        head->next = NULL;
    }
    return head;

}

List * initList(int * ec)
{
    //should just return NULL
    List * ptr;
    ptr = malloc(sizeof(List));

    if (ptr)
    {
        *ec = 0;
        ptr->next = NULL;
    }
    else
    {
        *ec = 1;
    }
    return ptr;

}

List * insertAtHead(int object, List * list, int * ec)
{
    //pointer to List that will be returned
    List * ptr;

    //create a new node(need to do every time you insert regardless of function), make its pointer point to list (the users already existing list)
    ptr = initList(ec);
    ptr->object = object;
    ptr->next = list;

    if (ec)
    {
        return ptr;
    }
    else
    {
        return list;
    }
}

//List * insertAtTail(int object, List * a, int * ec)
//List * removeList(int object, List * a, int * ec)


int getAtIndex(int index, List * list)
{    
    if(list == NULL)
    {
        printf("NULL list\n");
        return 0;
    }
    int object = 0;

    for (int i = 0; i < getListLength(list); i++)
    {
        //if object is equal to parameter index, set object to list-> object
        if(i == index)
        {
            object = list->next->object;
        }
    }

    //return object
    return object;
}

int getListLength(List * list)
{
    int length = 0;
    List * ptr;

    for(ptr = list; ptr != NULL; ptr = ptr->next)
    {
        length++;
    }
    return length;
}

List * freeList(List * list)
{
    //work on this after the lesson on tuesday
    free(list);
    
    return list;
}