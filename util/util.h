#include <stdio.h>

/* #include "../header/header.h" */
struct aa {
    unsigned int data;
    unsigned int search;
    int type;
};
typedef struct aa ARG;
enum MyEnum { Bst, Ll, Bs, Arr, Hash, Avl, Gen };
void randWriteStr(int range, int count, const char* fileName, int FLAG);
FILE* openFile(const char* filename);
