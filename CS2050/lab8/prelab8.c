#include "prelab8.h"

Node * makeNode(void * data, int priority)
{
    Node * n = malloc(sizeof(Node));

    if(n)
    {
        n->data = data;
        n->next = NULL;
        n->priority = priority;

    }
    return n;
}

void freeNode(Node * n)
{
    free(n);
}

/* This function returns the error code from the most
recently executed PQueue operation. 0 implies success,
1 implies out-of-memory error. Some functions may
document additional error conditions. NOTE: All
queue functions assign an error code. */
int pqGetErrorCode(PQueue q)
{
    return q.qstruct->ec;
}
/* This function returns an initialized PQueue variable.
Every queue variable must be initialized before
applying subsequent queue functions. */
PQueue pqInit()
{
    PQueue q;

    q.qstruct = malloc(sizeof(queueInfo));

    if(q.qstruct)
    {
        q.qstruct->head = NULL;
        q.qstruct->tail = NULL;
        q.qstruct->listLength = 0;
        q.qstruct->ec = 0;
    }

    return q;
}
/* This function enqueues an object and its associated
priority (int) into the PQueue.
For convenience, error code is returned directly
(and also can be obtained via pqGetErrorCode)  O(1) COMPLEXITY*/
int pqInsert(void * data, int priority, PQueue q)
{
    Node * n = makeNode(data, priority);

    if(n)
    {
        if(q.qstruct->head == NULL)
        {
            q.qstruct->tail = n;
        }
        n->next = q.qstruct->head;
        q.qstruct->head = n;
        q.qstruct->listLength++;
        q.qstruct->ec = 0;
        
    }
    else
    {
        q.qstruct->ec = 1;
    }

    return pqGetErrorCode(q);
}

int pqDeleteMin(int priority, PQueue q)
{
    Node * ptr, * temp;
    for (ptr = q.qstruct->head; ptr != NULL; ptr = ptr->next)
    {
        if(ptr->next->priority == priority)
        {
            temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
        }
    }
    q.qstruct->listLength--;
    
    return pqGetErrorCode(q);
}
/* This function returns the user object with
highest priority. NULL is returned if PQueue
is empty and error code is set to 2.
NOTE: User should check error code if null
objects are permitted in the queue. */
void * pqReturnMax(PQueue q)
{
    if(q.qstruct->head == NULL)
    {
        q.qstruct->ec = 2;
        return NULL;
    }
    
    Node * ptr;
    int max = q.qstruct->head->priority;
    void * d = q.qstruct->head->data;
    for (ptr = q.qstruct->head; ptr != NULL; ptr = ptr->next)
    {
        if(ptr->priority > max)
        {
            d = ptr->data;
        }
    }
    return d;
}
/* This function returns the number of objects
in the PQueue. */
int pqGetSize(PQueue q)
{
    return q.qstruct->listLength;
}
/* This function uninitializes a queue and frees all
memory associated with it. NOTE: value of PQueue
variable is undefined after this function is
applied, i.e., it should not be used unless
initialized again using queueInit. */
void pqFree(PQueue q)
{
    Node * temp, * ptr;
    for (ptr = q.qstruct->head; ptr != NULL; ptr = ptr->next)
    {
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
}