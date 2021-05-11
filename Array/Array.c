#include "Array.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

void insertArray(char **arrayOfPtr, const size_t index, const char *value) {
    arrayOfPtr[index] = (char *)malloc(sizeof(char) * (strlen(value) + 1));
    strcpy(arrayOfPtr[index], value);
}
char **createArray(const size_t length) {
    char **new = (char **)malloc(sizeof(char *) * length);
    return new;
}
int searchArray(char **arrayOfPtr, const char *value, const size_t length) {
    if (*arrayOfPtr == NULL) {
        return -1;
    }
    for (size_t i = 0; i < length; i++) {
        if (arrayOfPtr[i] == NULL) {
            return -1;
        }
        if (strcmp(value, arrayOfPtr[i]) == 0) {
            return i;
        }
    }
    return -1;
}
void testARR(int data, int search, char *filename, FILE *filePtr, FILE *searchPtr) {
    struct timeval tv;
    struct timeval start_tv;
    double elapsed = 0.0;

    char **arr = createArray(data);
    char buffer[1024];
    gettimeofday(&start_tv, NULL);

    for (size_t i = 0; i < data; i++) {
        fscanf(filePtr, "%s", buffer);
        insertArray(arr, i, buffer);
    }
    gettimeofday(&tv, NULL);
    elapsed = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    printf("%f\n", elapsed);
    gettimeofday(&start_tv, NULL);

    for (size_t i = 0; i < search; i++) {
        fscanf(searchPtr, "%s", buffer);
        searchArray(arr, buffer, search);
    }
    gettimeofday(&tv, NULL);
    elapsed = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    printf("%f\n", elapsed);
}
