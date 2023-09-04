#include "lab7.h"

//what head can point to
typedef struct nodestruct{
    void * data;
    struct nodestruct * next;
}Node;

//completion of info struct, contains a pointer to a node and 
//a variable for the length of the stack
struct Info{
    Node *head;
    int listLength;
};

Stack initStack()
{
    //creates new stack and allocates memory for the pointer inside it
    Stack s;
    s.info = malloc(sizeof(Node));

    if (s.info)
    {
        //initializes all the info pointer's information
        s.info->head = NULL;
        s.info->listLength = 0;
    }

    //returns the newly initialized stack
    return s;
}

int getSize(Stack s)
{
    //returns the listlength var stored in info
    return s.info->listLength;
}

void * peekStack(Stack s)
{
    if (s.info->head)
    {
        //just returns the data from the node at the beginning of the stack
        return s.info->head->data
    }
    
    return NULL;
}

int pushStack(Stack s, void *data)
{
    Node * cursor = malloc(sizeof(Node));
    if (n)
    {
        cursor->data = data;
        cursor->next = NULL;
    }
    
    //error test
    if (s.info->head)
    {
        s.info->head = cursor;
        s.info->listLength++;
        return 0;
    }
    return 1;
}

void * popStack(Stack s)
{
    Node * cursor = s.info->head;
    
    //for if the stack is empty
    if(s.info->head)
    {
        s.info->head = s.info->head->next;
        s.info->listLength--;
        return freeNode(cursor);
    }

    //returns temp
    return NULL;
}

void * getAtIndex(Stack s, int index)
{
    //for loop and i, which will test for index
    Info * ptr;
    int i = 0;
    for (ptr = s.info; ptr != NULL; ptr->head = ptr->head->next)
    {
        //if index equals i, return the data, else add 1 to i
        if(index == i)
        {
            return ptr->head->data;
        }
        else
        {
            i++;
        }
    }
    //if the index is not valid, return null (catch all)
    return NULL;
}

void freeStack(Stack s)
{
    //goes through the stack and pops out everything
    for (ptr = s.info; ptr != NULL; ptr->head = ptr->head->next)
    {
        popStack(s);
    }

    free(s.info);
}
