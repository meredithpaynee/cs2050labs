#include "lab8.h"

//node struct including priority
typedef struct nodestruct{
    void * data;
    struct nodestruct * next;
    int priority;
}Node;

//finishing the nfo struct
struct Info{
    Node *head, *tail;
    int listLength;
    int ec;
};


//helper function that makes node
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

// O(1)
int pqGetErrorCode(PQueue q)
{
    //return the error code variable
    return q.info->ec;
}

// O(1)
PQueue pqInit()
{
    //set q variable and allocates q.Info pointer.
    PQueue q;

    q.info = malloc(sizeof(Info));

    //malloc test, if it worked set all the variables
    if(q.info)
    {
        q.info->head = NULL;
        q.info->tail = NULL;
        q.info->listLength = 0;
        q.info->ec = 0;
    }

    //return a PQ
    return q;
}

// O(n)
int pqInsert(void *data, int priority, PQueue q)
{
    Node * n = makeNode(data, priority);
    Node * ptr;

    //malloc failure test
    if(n)
    {
        //test for the first node in the list
        if(q.info->head->priority > priority)
            {
                //set n->next to point to the head node and reset head to n
                n->next = q.info->head;
                q.info->head = n; 
                q.info->ec = 0;
                q.info->listLength++;
                return pqGetErrorCode(q); 
            }

        //for loop for the rest
        for (ptr = q.info->head; ptr != NULL; ptr = ptr->next)
        {
            //compare the priorities
            if(ptr->next->priority >= priority)
            {
                //set pointer to n and n->next to ptr->next
                ptr = n;
                n->next = ptr->next;
                q.info->listLength++;
                q.info->ec = 0;
                return pqGetErrorCode(q);
            }
        }        
    }
    
    //if n malloc fails
    q.info->ec = 1;
    return pqGetErrorCode(q);
}

// O(1)
void * pqRemoveMax(PQueue q)
{
    //error test for if the queue is empty
    if (q.info->head == NULL)
    {
        q.info->ec = 2; 
        return NULL;
    }
    
    //temp var to hold the last node (which has highest priority)
    void * temp = q.info->tail->data;
    
    Node * ptr;
    //I know it specifies 0(1) but I'm just not sure how to do it with that complexity
    //because there is no way to access the node before the last one without a for loop
    for (ptr = q.info->head; ptr != NULL; ptr = ptr->next)
    {
        //if ptr->next is the last one in the list, set ptr->next to null and free the node
        if (ptr->next->next == NULL)
        {
            ptr->next = NULL;
            free(ptr);
        }
    }

    //subtract one and return the data;
    q.info->listLength--;
    return temp;
}

// O(1)
void * pqPeek(PQueue q)
{
    //because we have a direct pointer to the tail, which has the highest priority, 
    //we can just return the data from the tail pointer
    return q.info->tail->data;
}

// O(1)
int pqGetSize(PQueue q)
{
    //returns list length variable
    return q.info->listLength;
}

// O(n)
void pqFree(PQueue q)
{
    //temp node pointer and ptr to go through the list
    Node * temp, * ptr;
    for (ptr = q.info->head; ptr != NULL; ptr = ptr->next)
    {
        //set the temp variable to the next node, free pointer, and set it to the next node
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
}