#include <stdio.h>
#include <stdlib.h>

typedef struct listStruct {
    int object;
    struct listStruct * next;
} List;

List * initList(int *);

List * insertAtHead(int, List *, int *);

int getAtIndex(int, List *);

int getListLength(List *);

List * freeList(List *);