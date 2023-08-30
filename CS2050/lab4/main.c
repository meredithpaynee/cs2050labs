#include "lab4.h"

int main(void)
{


    int elementSize = sizeof(int) + sizeof(float) + sizeof(int) + sizeof(short);
    InventoryItem * a = makeArray(8, elementSize);

    float weight = 3.5;

    printf("Size: %d\n", getSize(a));
    for (int i = 0; i < getSize(a); i++) 
    {
		a[i].ID = (i + 100);
        a[i].weight = weight;
        weight += 1.0;
        a[i].stockCount = i + 30;
        a[i].colors = 2;

	}
    for (int i = 0; i < getSize(a); i++) 
    {
        printf("ID: %d Weight: %f stockcount: %d color: %d\n", a[i].ID, a[i].weight, a[i].stockCount, a[i].colors);
    }

    printf("\ncount: %d\n", countGreaterID(a, 103));
    
    //fclose(fp);
    freeArray(a);

}