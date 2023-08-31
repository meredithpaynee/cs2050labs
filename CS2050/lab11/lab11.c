#include "lab11.h"

typedef struct nodestruct{
    struct nodestruct * left; 
    struct nodestruct * right;
    int data;
}Node;

struct BST{
    int ec;
    int size;
    Node * root;
};

//init node helper, initalizes root in BST
Node * initNode()
{
    //initialize root
    Node * root = malloc(sizeof(Node));

    //if allocation is successful, set root pointers to null and return root
    if (root)
    {
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    //for malloc failure
    return NULL;
}

//helper function for insertion
Node * insert(Node * tree, int data)
{
    //test if tree is empty, create a new node and return the tree
    if (tree == NULL)
    {
        tree = initNode();
        tree->data = data;
        return tree;
    }

    //else test for the value of the data and move to the left or right recursively
    if (data < tree->data)
    {
        return insert(tree->left, data);
    }
    else
    {
        return insert(tree->right, data);
    }
}

//helper function for getMinBST
int getMin(Node * tree)
{
    //if there is nothing smaller than the root, its the smallest so return it
    if (tree->left == NULL)
    {
        return tree->data;
    }

    //if not, move the the left recursively
    return getMin(tree->left);
}

//helper function for preOrderPrintBST
void preOrderPrint(Node *tree)
{
    //if the tree is empty do nothing
    if (tree == NULL)
    {
        return;
    }
    
    //print the data in the given node and print the rest recursively
    printf("%d\n", tree->data);
    preOrderPrint(tree->left);
    preOrderPrint(tree->right);

}

//helper function for freeBST
void freeRoot(Node *tree)
{
    //if the tree is empty do nothing 
    if (tree == NULL)
    {
        return;
    }

    //free the left part and right part of the tree
    freeRoot(tree->left);
    freeRoot(tree->right);
    free(tree);
}


// O(1)
BST * initBST()
{
    //create pointer to a tree and allocate memory for it
    BST * top;
    top = malloc(sizeof(BST));

    //if malloc was successful, set the error code and size to 0 and initialize root
    if (top)
    {
        top->ec = 0;
        top->size = 0;
        top->root = initNode();
        return top;
    }

    //for if malloc does not succeed
    return NULL;
}

// O(log(n))
int insertBST(BST *top, int data)
{   
    //set tree to new insert
    top->root = insert(top->root, data);

    //error codes
    if (top)
    {
        top->ec = 0;
    }
    else
    {
        top->ec = 1;
    }

    //add to size and return error code
    top->size++;
    return top->ec;
}

// O(1)
int getSizeBST(BST *top)
{
    return top->size;
}
 
// O(log(n))
int getMinBST(BST *top)
{
    //use helper function to get the min and return
    int min = getMin(top->root);
    return min;
}

// O(n)
void preOrderPrintBST(BST *top)
{
    //if the tree is empty do nothing
    if (top == NULL)
    {
        return;
    }
    
    //if not call helper function for preOrderPrint
    preOrderPrint(top->root);
}

// O(n)
void freeBST(BST *top)
{
    //free the root in the BST then free the entire tree
    freeRoot(top->root);
    free(top);
}
