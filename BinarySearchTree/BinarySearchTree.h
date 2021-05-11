#include <stdio.h>
struct bst {
    char *value;
    struct bst *left;
    struct bst *right;
};
typedef struct bst BST;
/* BST *insertNode(BST *r, const char *value); */
/* void printBST(const BST *root, const int FLAG); */
/* BST *findNode(BST *root, const char *value); */
void testBST(int data, int search, char *filename, FILE *filePtr, FILE *searchPtr);

