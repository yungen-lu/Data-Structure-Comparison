#include "ArrayWithBinarySearch.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "../Array/Array.h"
#include "../util/util.h"
static size_t searchArrayWithBinarySearch(char **arrayOfPtr, const char *value, size_t start, size_t end) {
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
static int cmpStr(const void *a, const void *b) {
    const char *a1 = *(char **)a;
    const char *b1 = *(char **)b;
    return strcmp(a1, b1);
}

void testBS(int data, int search, const char *fileName, const char *searchName) {
    FILE *filePtr = openFile(fileName);
    FILE *searchPtr = openFile(searchName);

    struct timeval tv;
    struct timeval start_tv;
    double elapsed = 0.0;
    double elapsed2 = 0.0;
    gettimeofday(&start_tv, NULL);
    char **arr = createArray(data);
    char buffer[1024];

    for (size_t i = 0; i < data; i++) {
        fscanf(filePtr, "%1023s", buffer);
        insertArray(arr, i, buffer);
    }
    qsort(arr, data, sizeof(char *), cmpStr);
    gettimeofday(&tv, NULL);
    elapsed = ((double)(tv.tv_sec - start_tv.tv_sec) + (double)(tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    gettimeofday(&start_tv, NULL);

    for (size_t i = 0; i < search; i++) {
        fscanf(searchPtr, "%1023s", buffer);
        /* searchArray(arr, buffer, search); */
        searchArrayWithBinarySearch(arr, buffer, 0, data - 1);
    }
    gettimeofday(&tv, NULL);
    free(arr);
    elapsed2 = ((double)(tv.tv_sec - start_tv.tv_sec) + (double)(tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    printf("arraywithbs %d %d %f %f\n", data, search, elapsed, elapsed2);
    fclose(filePtr);
    fclose(searchPtr);
}
