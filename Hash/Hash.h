#include <stdio.h>
void testHASH(int data, int search, const char *fileName, const char *searchName);
struct hh {
    char* string;
    struct hh* next;
};
typedef struct hh HH;
size_t hash(const char* string, size_t maxHash);
HH** createHA(size_t len);
HH* find(HH** r, const char* string, size_t maxHash);
void insert(HH** r, const char* string, size_t index);

