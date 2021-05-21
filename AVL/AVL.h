struct Node {
    struct Node *left;
    struct Node *right;
    char *string;
    int height;
};
typedef struct Node AVL;
void testAVL(int data, int search, const char *fileName, const char *searchName);
