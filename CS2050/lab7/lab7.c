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
    //initializes all the info pointer's information
    s.info->head = NULL;
    s.info->listLength = 0;

    //error tests
    if(!s.info)
    {
        s.info = NULL;
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
    //just returns the data from the node at the beginning of the stack
    return s.info->head->data;
}

int pushStack(Stack s, void *data)
{
    //makes the data given point to s.info, putting it before the stack
    data = s.info;
    //sets the head to point to data
    s.info->head = data;
    //adds one to the listlength var
    s.info->listLength += 1;

    //error test
    if (s.info->head == NULL)
    {
        return 1;
    }
    return 0;
}

void * popStack(Stack s)
{
    //for if the stack is empty
    if(s.info->head == NULL)
    {
        return NULL;
    }
    //creates pointer to store the popped node
    void * temp;
    temp = s.info->head;
    //makes it point to the next node in line
    s.info->head = s.info->head->next;
    //subtracts one from the listlength
    s.info->listLength -= 1;

    //returns temp
    return temp;
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
    //goes through the stack and frees everything
    Info * ptr;
    for (ptr = s.info; ptr != NULL; ptr->head = ptr->head->next)
    {
        free(ptr);
    }
}