#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    struct Node *left;
    struct Node *right;
    char *string;
    int height;
};
typedef struct Node AVL;
void testAVL(int data, int search, char *filename, FILE *filePtr, FILE *searchPtr);