#include <stdio.h>
#include <stdlib.h>

typedef struct nodestruct{
    void * data;
    struct nodestruct * next;
    int priority;
}Node;


typedef struct{
    Node *head, *tail;
    int listLength;
    int ec;
}queueInfo;

typedef struct{
    queueInfo * qstruct;
}PQueue;

int pqGetErrorCode(PQueue);
PQueue pqInit();
int pqInsert(void *, int, PQueue);
void * pqRemoveMax(PQueue);
int pqGetSize(PQueue);
void pqFree(PQueue);