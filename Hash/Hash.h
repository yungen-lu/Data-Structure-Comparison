#include <stdio.h>
void testHASH(int data, int search, const char *fileName, const char *searchName);
struct hh {
    char* string;
    int count;
    struct hh* next;
};
typedef struct hh HH;
