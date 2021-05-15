#include "util.h"

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
/* #include "../header/header.h" */
void printLinkList(LinkedList* i) {
    while (i) {
        printf("%s\n", i->string);
        i = i->next;
    }
}
int getData(char* string) {
    int re;
    sscanf(string, "%d", &re);
    return re;
}

void randWriteStr(int range, int count, const char* fileName) {
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* randomString;
    FILE* fptr;
    fptr = fopen(fileName, "w");
    if (fptr == NULL) {
        fprintf(stderr, "can not scan file\n");
        return;
    }
    srand(time(0));
    for (int i = 0; i < count; i++) {
        size_t len = (rand() % range) + 1;
        randomString = malloc(sizeof(char) * len + 1);

        if (randomString) {
            int l = (int)(sizeof(charset) - 1);
            int key;
            for (int n = 0; n < len; n++) {
                key = rand() % l;
                randomString[n] = charset[key];
            }

            randomString[len] = '\0';
        }
        fprintf(fptr, "%s\n", randomString);
        free(randomString);
    }
    fclose(fptr);
}
FILE* openFile(const char* filename) {
    FILE* fptr;
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        fprintf(stderr, "can not scan file\n");
        return NULL;
    }
    /* fclose(fptr); */
    return fptr;
}
