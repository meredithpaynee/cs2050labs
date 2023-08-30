#include "lab5.h"

int makeList(Node **list)
{
    *list = NULL;
    //returns 0
    return 0;
}

int getSize(Node *list)
{
    //local variable to represent size of list
    int length = 0;

    //pointer to increment through the list
    Node * ptr;
    for(ptr = list; ptr != NULL; ptr = ptr->next)
    {
        //adds 1 to length for every node in the list
        length++;
    }
    
    //returns length of the list
    return length;
}

int insertAtHead(Node **list, void *data)
{
    //create new node and set its data and next to the parameter and the already existing list
    Node * new = malloc(sizeof(Node));

    if(new == NULL)
    {
        return 1;
    }

    (new)->data = data;
    (new)->next = *list;
    *list = new;

    return 0;
}    

void * removeFromTail(Node **list)
{
    //local variable for the last node's data
    void * data;
    if (list == NULL)
    {
        return NULL;
    }

    Node * ptr;
    //using *list to increment through the list to get to the end
    for(ptr = *list; ptr != NULL; ptr = ptr->next)
    {
        //for removal, you need a pointer to the 2nd to last element (whos next points to the last)
        //the second to last's list->next->next will point to null 
        if((*list)->next->next == NULL)
        {
            //sets data to the last node's data value
            data = (*list)->next->data;
            //removes the last node
            (*list)->next = NULL;
        }
    }

    return data;

}

void freeList(Node **list)
{
    Node * temp, * ptr;
    
    for(ptr = *list; ptr != NULL; ptr = ptr->next)
    {
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }

    //set the pointer to list to NULL
    *list = NULL;
}

