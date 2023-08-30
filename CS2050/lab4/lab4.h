#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int ID;
	float weight;
	int stockCount;
	short colors;
} InventoryItem;


void * makeArray(int arraySize, int elementSize);

int getSize(void *array);

int countGreaterID(InventoryItem *items, int minID);

void freeArray(void *array);

