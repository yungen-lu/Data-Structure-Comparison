#include "Hash.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
static size_t hash(char* string, size_t maxHash) {
    char* ptr = string;
    size_t i = 1;
    size_t r = 65;
    while (*ptr) {
        i = i * r + *ptr;
        ptr++;
    }
    return i % maxHash;
}
static void insert(HH** r, char* string, size_t index) {
    HH*(*ptr) = &r[index];
    if ((*ptr) == NULL) {
        (*ptr) = (HH*)malloc(sizeof(HH));
        (*ptr)->next = NULL;
        (*ptr)->count = 1;
        (*ptr)->string = (char*)malloc(sizeof(char) * strlen(string) + 2);
        strcpy((*ptr)->string, string);
        return;
    }
    HH* last;
    while ((*ptr) != NULL) {
        if (strcmp((*ptr)->string, string) == 0) {
            (*ptr)->count++;
            return;
        }
        last = (*ptr);
        (*ptr) = (*ptr)->next;
    }
    (*ptr) = (HH*)malloc(sizeof(HH));
    (*ptr)->next = NULL;
    (*ptr)->count = 1;
    (*ptr)->string = (char*)malloc(sizeof(char) * strlen(string) + 2);
    strcpy((*ptr)->string, string);
    last->next = (*ptr);
    return;
}
static HH* find(HH** r, char* string, size_t maxHash) {
    if (r == NULL) {
        return NULL;
    }
    HH* ptr = r[hash(string, maxHash)];
    while (ptr) {
        if (strcmp(ptr->string, string) == 0) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}
static HH** createHA(size_t len) {
    HH** new = (HH**)malloc(sizeof(HH*) * len);
    for (size_t i = 0; i < len; i++) {
        new[i] = NULL;
    }
    return new;
}
void testHASH(int data, int search, char* filename, FILE* filePtr, FILE* searchPtr) {
    struct timeval tv;
    struct timeval start_tv;
    double elapsed = 0.0;
    gettimeofday(&start_tv, NULL);
    size_t len = data * 2;
    HH** ha = createHA(len);
    char buffer[1024];

    for (size_t i = 0; i < data; i++) {
        fscanf(filePtr, "%s", buffer);
        insert(ha, buffer, hash(buffer, len));
    }
    gettimeofday(&tv, NULL);
    elapsed = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    printf("%f\n", elapsed);
    gettimeofday(&start_tv, NULL);

    for (size_t i = 0; i < search; i++) {
        fscanf(searchPtr, "%s", buffer);
        find(ha, buffer, len);
    }
    gettimeofday(&tv, NULL);
    free(ha);
    elapsed = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    printf("%f\n", elapsed);
}
