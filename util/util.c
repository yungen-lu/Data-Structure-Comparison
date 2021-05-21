#include "util.h"

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "../Hash/Hash.h"
int findDup(int* hashTable, const char* string, int len) {
    size_t idx = hash(string, len);
    if (hashTable[idx] == 1) {
        return 0;
    } else {
        hashTable[idx] = 1;
        return 1;
    }
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
    int* hashTable = (int*)calloc(count, sizeof(int));
    srand(time(NULL));
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
        if (findDup(hashTable, randomString, count)) {
            fprintf(fptr, "%s\n", randomString);
        } else {
            i--;
        }
        free(randomString);
    }
    fclose(fptr);
}
FILE* openFile(const char* filename) {
    FILE* fptr;
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        fprintf(stderr, "can not open file\n");
        return NULL;
    }
    return fptr;
}
