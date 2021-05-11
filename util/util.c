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

/* ARG* getArg(char* argv[], int argc) { ARG* new = malloc(sizeof(ARG)); } */
ARG* parseArg(char* argv[], int argc) {
    ARG* new = (ARG*)malloc(sizeof(ARG));
    for (size_t i = 1; i < argc; i++) {
        /* char* argv[i] = argv[i]; */
        if (argv[i][0] == '-' && (isalpha(argv[i][1]))) {
            switch (argv[i][1]) {
                case 'd':
                    new->data = getData(argv[i + 1]);
                    printf("%d\n", new->data);
                    break;
                case 'q':
                    new->search = getData(argv[i + 1]);
                    printf("%d\n", new->search);
                    break;
            }
        } else if (strncmp(argv[i], "--", 2) == 0) {
            if (strncmp(argv[i] + 2, "bst", 3) == 0) {
                printf("bst\n");
                new->type = Bst;
            } else if (strncmp(argv[i] + 2, "bs", 2) == 0) {
                printf("bs\n");
                new->type = Bs;
            } else if (strncmp(argv[i] + 2, "arr", 3) == 0) {
                printf("arr\n");
                new->type = Arr;
            } else if (strncmp(argv[i] + 2, "ll", 2) == 0) {
                printf("ll\n");
                new->type = Ll;
            } else if (strncmp(argv[i] + 2, "hash", 4) == 0) {
                printf("hash\n");
                new->type = Hash;
            }
        }
    }
    return new;
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
