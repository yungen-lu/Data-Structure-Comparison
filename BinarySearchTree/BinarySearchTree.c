#include "BinarySearchTree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

static BST *insertNode(BST *r, const char *value) {
    BST *root = r;
    if (root == NULL) {
        root = (BST *)malloc(sizeof(BST));
        root->value = (char *)malloc(sizeof(char) * (strlen(value) + 1));
        strcpy(root->value, value);
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    BST *last;
    int a;
    while (root) {
        a = strcmp(value, root->value);
        last = root;
        if (a > 0) {
            root = root->right;
        } else if (a < 0) {
            root = root->left;
        } else {
            return r;
        }
    }
    root = (BST *)malloc(sizeof(BST));
    root->value = (char *)malloc(sizeof(char) * (strlen(value) + 1));
    strcpy(root->value, value);
    root->left = NULL;
    root->right = NULL;
    if (a > 0) {
        last->right = root;
    } else {
        last->left = root;
    }
    return r;
}
static BST *findNode(BST *root, const char *value) {
    while (root) {
        int a = strcmp(root->value, value);
        if (a == 0) {
            return root;
        } else if (a > 0) {
            root = root->left;
        } else if (a < 0) {
            root = root->right;
        }
    }
    return NULL;
}
void testBST(int data, int search, FILE *filePtr, FILE *searchPtr) {
    struct timeval tv;
    struct timeval start_tv;
    double elapsed = 0.0;

    gettimeofday(&start_tv, NULL);
    BST *node = NULL;
    char buffer[1024];

    for (size_t i = 0; i < data; i++) {
        fscanf(filePtr, "%1023s", buffer);
        node = insertNode(node, buffer);
    }
    gettimeofday(&tv, NULL);
    elapsed = ((double)(tv.tv_sec - start_tv.tv_sec) + (double)(tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    printf("%f\n", elapsed);
    gettimeofday(&start_tv, NULL);

    for (size_t i = 0; i < search; i++) {
        fscanf(searchPtr, "%1023s", buffer);
        findNode(node, buffer);
    }
    gettimeofday(&tv, NULL);
    free(node);
    elapsed = ((double)(tv.tv_sec - start_tv.tv_sec) + (double)(tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    printf("%f\n", elapsed);
}
