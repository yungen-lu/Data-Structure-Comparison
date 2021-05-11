#include "ArrayWithBinarySearch.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "../Array/Array.h"
/* void insertArray(const char **arrayOfPtr, const char *value) { */
/*     if (*arrayOfPtr == NULL) { */
/*         char *newString = (char *)malloc(sizeof(char) * (strlen(value) + 1)); */
/*         return; */
/*     } */
/*     size_t i = 1; */
/*     while ((strcmp(arrayOfPtr[i], value)) < 0) { */
/*         i++; */
/*     } */
/* } */
int searchArrayWithBinarySearch(char **arrayOfPtr, const char *value, size_t start, size_t end) {
    if (start > end) {
        return -1;
    }
    size_t mid = (start + end) / 2;
    int re = strcmp(arrayOfPtr[mid], value);
    if (re == 0) {
        return mid;
    }
    if (re > 0) {
        return searchArrayWithBinarySearch(arrayOfPtr, value, start, mid - 1);
    } else {
        return searchArrayWithBinarySearch(arrayOfPtr, value, mid + 1, end);
    }
}
int cmpStr(const void *a, const void *b) {
    const char *a1 = *(char **)a;
    const char *b1 = *(char **)b;
    return strcmp(a1, b1);
}

void testBS(int data, int search, char *filename, FILE *filePtr, FILE *searchPtr) {
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
    qsort(arr, data, sizeof(char *), cmpStr);
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
