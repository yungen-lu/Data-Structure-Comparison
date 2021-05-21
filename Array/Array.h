#include <stddef.h>
char **createArray(const size_t length);
size_t searchArray(char **arrayOfPtr, const char *value, const size_t length);
void insertArray(char **arrayOfPtr, const size_t index, const char *value);
void testARR(int data, int search,const char *fileName, const char *searchName);
