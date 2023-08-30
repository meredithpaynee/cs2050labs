#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	Node *next;
	void *data;
};


int makeList(Node **list);

int getSize(Node *list);

void * getAtIndex(Node *list, int index);

int insertAtHead(Node *list, void *data);

void * removeFromTail(Node *list);

void freeList(Node **list);

