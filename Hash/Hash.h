#include <stdio.h>
void testHASH(int data, int search, FILE* filePtr, FILE* searchPtr);
struct hh {
    char* string;
    int count;
    struct hh* next;
};
typedef struct hh HH;
