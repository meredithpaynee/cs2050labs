#include <stdio.h>
#include <stdlib.h>

typedef struct nodestruct{
    void * object;
    struct nodestruct * next;
}Node;

typedef struct{
    Node *head, *tail;
    int listLength;
    int ec;
}queueInfo;

typedef struct{
    queueInfo * qstruct;
}Queue;

int getQueueErrorCode(Queue);
Queue queueInit();
int enqueue(void*, Queue);
void * dequeue(Queue);
int getQueueSize(Queue);
void freeQueue(Queue);