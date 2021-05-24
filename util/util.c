#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../Hash/Hash.h"
int findDup(HH** hashTable, const char* string, int len) {
    if (find(hashTable, string, len) == NULL)
        return 1;
    else
        return 0;
}

void randWriteStr(int range, int count, const char* fileName, int FLAG) {
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* randomString;
    FILE* fptr;
    fptr = fopen(fileName, "w");
    if (fptr == NULL) {
        fprintf(stderr, "can not scan file\n");
        return;
    }
    /* int* hashTable = (int*)calloc(count * 5, sizeof(int)); */
    size_t hashLen = count * 5;
    HH** hashTable = createHA(hashLen);
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
        if (FLAG == 1) {
            if (find(hashTable, randomString, hashLen) == NULL) {
                fprintf(fptr, "%s\n", randomString);
                insert(hashTable, randomString, hash(randomString, hashLen));
            } else {
                i--;
            }
        } else {
            fprintf(fptr, "%s\n", randomString);
        }
        free(randomString);
    }
    free(hashTable);
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
