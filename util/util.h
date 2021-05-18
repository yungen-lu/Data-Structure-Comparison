#include <stdio.h>

#include "../header/header.h"
struct aa {
    unsigned int data;
    unsigned int search;
    int type;
};
typedef struct aa ARG;
enum MyEnum { Bst, Ll, Bs, Arr, Hash ,Avl};
void printLinkList(LinkedList* i);
void randWriteStr(int range, int count, const char* fileName);
FILE* openFile(const char* filename);
