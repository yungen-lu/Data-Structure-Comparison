#include <stddef.h>
#include <stdio.h>
void insertArray(char **arrayOfPtr, const size_t index, const char *value);
char **createArray(const size_t length);
void testARR(int data, int search, char *filename, FILE *filePtr, FILE *searchPtr);
int searchArray(char **arrayOfPtr, const char *value, const size_t length);

