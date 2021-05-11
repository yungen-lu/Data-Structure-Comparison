#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
LinkedList *insertLinkedList(LinkedList *i, const char *value) {
    if (i == NULL) {
        i = (LinkedList *)malloc(sizeof(LinkedList));
        i->string = (char *)malloc(sizeof(char) * strlen(value) + 1);
        strcpy(i->string, value);
        return i;
    }

    LinkedList *new = (LinkedList *)malloc(sizeof(LinkedList));
    new->string = (char *)malloc(sizeof(char) * strlen(value) + 1);
    strcpy(new->string, value);
    new->next = i;
    return new;
}
LinkedList *findLinkedList(LinkedList *i, const char *value) {
    while (i) {
        int a = strcmp(i->string, value);
        if (a != 0) {
            i = i->next;
        }
    }
    return NULL;
}
void testLL(int data, int search, char *filename, FILE *filePtr, FILE *searchPtr) {
    struct timeval tv;
    struct timeval start_tv;
    double elapsed = 0.0;

    LinkedList *node = NULL;
    char buffer[1024];
    gettimeofday(&start_tv, NULL);

    for (size_t i = 0; i < data; i++) {
        fscanf(filePtr, "%s", buffer);
        node = insertLinkedList(node, buffer);
    }
    gettimeofday(&tv, NULL);
    elapsed = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    printf("%f\n", elapsed);
    gettimeofday(&start_tv, NULL);

    for (size_t i = 0; i < search; i++) {
        fscanf(searchPtr, "%s", buffer);
        findLinkedList(node, buffer);
    }
    gettimeofday(&tv, NULL);
    elapsed = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    printf("%f\n", elapsed);
}
