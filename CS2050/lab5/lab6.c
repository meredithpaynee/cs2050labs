#include "lab6.h"

int makeList(Node **list)
{
    //sets the list equal to NULL
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
    //starts at list->next to not count the dummy node in the size
    for(ptr = list->next; ptr != NULL; ptr = ptr->next)
    {
        //adds 1 to length for every node in the list (minus dummy)
        length++;
    }
    
    //returns length of the list
    return length;
}

void * getAtIndex(Node *list, int index)
{
    if(index < 0 || index >= getSize(list))
    {
        return NULL;
    }
    void * object;
    int i = -1;

    Node * ptr;
    //starts at list->next to pass over the dummy node
    for(ptr = list->next; ptr != NULL; ptr = ptr->next)
    {
        //index tester
        i++;
        //if object is equal to parameter index, set object to ptr->object
        if(i == index)
        {
            //this is where one of the original errors was, original line was object = ptr->object
            object = ptr->data;
        }
    }

    //return object
    return object;
}

int insertAtHead(Node *list, void *data)
{
    //create new node
    Node * new = malloc(sizeof(Node));

    //error test
    if(new == NULL)
    {
        return 1;
    }

    //set its data and next to the parameter set the  dummy node's pointer equal to the new node
    new->data = data;
    //this is where one of the original errors was, the line before was new->next = *list. I just removed the *
    new->next = list;
    list->next = new;

    return 0;
}

void * removeFromTail(Node *list)
{
    //local variable for the last node's data
    void * data;
    if (list == NULL)
    {
        return NULL;
    }

    Node * ptr;
    //using list to increment through the list to get to the end
    for(ptr = list; ptr != NULL; ptr = ptr->next)
    {
        //for removal, you need a pointer to the 2nd to last element (whos next points to the last)
        //the second to last's list->next->next will point to null 
        if(list->next->next == NULL)
        {
            //sets data to the last node's data value
            data = list->next->data;
            //removes the last node
            list->next = NULL;
        }
    }

    return data;
}

void freeList(Node **list)
{
    //create temp node and counter node
    Node * temp, * ptr;
    
    //for loop to increment through and free all elements
    for(ptr = *list; ptr != NULL; ptr = ptr->next)
    {
        //set temp equal to the next node
        temp = ptr->next;
        //free the current node
        free(ptr);
        //set the pointer to point to the next node 
        ptr = temp;
    }

    //set the pointer to list to NULL
    *list = NULL;
}

