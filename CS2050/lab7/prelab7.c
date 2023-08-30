#include "prelab7.h"


/* This function returns the error code from the most 
   recently executed queue operation. 0 implies success, 
   1 implies out-of-memory error. Some functions may 
   document additional error conditions. NOTE: All  
   queue functions assign an error code.   */
int getQueueErrorCode(Queue q)
{
    return q.qstruct->ec;
}

/* This function returns an initialized Queue variable.  
   Every queue variable must be initialized before      
   applying subsequent queue functions. */
Queue queueInit()
{
    Queue q;
    q.qstruct = malloc(sizeof(Node));
    q.qstruct->head = NULL;
    q.qstruct->tail = NULL;
    q.qstruct->listLength = 0;
    q.qstruct->ec = 0;

    if(!(q.qstruct))
    {
        q.qstruct->ec = 1;
    }
    return q;
}

/* This function enqueues an object into the queue.  
   For convenience, error code is returned directly 
   (and also can be obtained via getQueueErrorCode) */
int enqueue(void * object, Queue q)
{
    q.qstruct->tail = object;
    q.qstruct->listLength += 1;

    if (q.qstruct->tail == NULL)
    {
        q.qstruct->ec = 2;
    }
    return getQueueErrorCode(q);
}

/* This function performs dequeue and returns  
   object at front of queue (the object taken out). NULL is returned 
   if queue is empty and error code is set to 2.  
   NOTE: User should check error code if null  
   objects are permitted in the queue. */
void * dequeue(Queue q)
{
    if(q.qstruct->head == NULL)
    {
        q.qstruct->ec = 2;
        return NULL;
    }
    void * temp;
    temp = q.qstruct->head;
    q.qstruct->head = q.qstruct->head->next;
    q.qstruct->listLength -= 1;

    return temp;
}

/* This function returns the number of objects 
   in the queue. Need to store the size somewhere, O() needs to be 1 */ 
int getQueueSize(Queue q)
{
    return q.qstruct->listLength;
}

/* This function uninitializes a queue and frees all  
   memory associated with it. NOTE: value of Queue  
   variable is undefined after this function is  
   applied, i.e., it should not be used unless 
   initialized again using queueInit. */ 
void freeQueue(Queue q)
{
    queueInfo * ptr;
    for (ptr = q.qstruct; ptr != NULL; ptr->head = ptr->head->next)
    {
        free(ptr);
    }
}

/*Your underlying representation should be a simple (or circular) linked list with tail pointer so that all 
functions take only O(1) time except for freeQueue, which obviously must take time proportional to the 
size of the queue. The real challenge here is designing your implementation so that the user never needs 
to pass anything by reference. That means that your Queue struct can’t contain anything that will ever 
change after it is initialized.  HINT: queueInit doesn’t need to allocate a Queue struct, and if its pointer is 
NULL, then that can be used by getQueueErrorCode to conclude...  
 
This is the first time you've been given a specification that includes a performance constraint. From now 
on your documentation – both for prelabs and labs – should include the computational complexity for 
every function. That's easy for this prelab because all functions other than freeQueue are required to 
have O(1) run-time complexity. */



int main(void)
{
    int n = 9;
    int r = 3;
    Queue test = queueInit();
    printf("%d\n", getQueueErrorCode(test));
    printf("enqueue: %d\n", enqueue(&n, test));
    printf("enqueue: %d\n", enqueue(&r, test));
    printf("Size: %d\n", getQueueSize(test));
    dequeue(test);
    printf("size: %d\n", getQueueSize(test));
}