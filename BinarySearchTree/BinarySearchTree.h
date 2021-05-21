struct bst {
    char *value;
    struct bst *left;
    struct bst *right;
};
typedef struct bst BST;
void testBST(int data, int search, const char *fileName, const char *searchName);
