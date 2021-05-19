#include <stddef.h>
#include <stdio.h>
char **createArray(const size_t length);
size_t searchArray(char **arrayOfPtr, const char *value, const size_t length);
void insertArray(char **arrayOfPtr, const size_t index, const char *value);
void testARR(int data, int search, FILE *filePtr, FILE *searchPtr);
