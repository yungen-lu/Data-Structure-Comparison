#include "util.h"

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
int findDup(char** arrayOfStr, const char* string, int len) {
    for (int j = 0; j < len; j++) {
        if (strcmp(arrayOfStr[j], string) == 0) {
            printf("DUP\n");
            return 0;
        }
    }
    return 1;
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
    char** arrayOfStr = calloc(count, sizeof(char*));
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
        if (findDup(arrayOfStr, randomString, i)) {
            /* fprintf(fptr, "%s\n", randomString); */
            /* strcpy(arrayOfStr[i], randomString); */
            arrayOfStr[i] = strdup(randomString);
        } else {
            i--;
        }
        free(randomString);
    }
    for (int k = 0; k < count; k++) {
        fprintf(fptr, "%s\n", arrayOfStr[k]);
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
