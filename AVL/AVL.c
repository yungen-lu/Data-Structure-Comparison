#include "AVL.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
static int NodeHeight(AVL *p) {
    int left, right;
    left = (p && p->left ? p->left->height : 0);
    right = (p && p->right ? p->right->height : 0);
    return left > right ? left + 1 : right + 1;
}
static int balanceFactor(AVL *p) {
    int left, right;
    left = (p && p->left ? p->left->height : 0);
    right = (p && p->right ? p->right->height : 0);
    return left - right;
}
static AVL *LL(AVL *p) {
    AVL *pl = p->left;
    AVL *plr = pl->right;
    pl->right = p;
    p->left = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    return pl;
}
static AVL *RR(AVL *p) {
    AVL *pr = p->right;
    AVL *prl = pr->left;
    pr->left = p;
    p->right = prl;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    return pr;
}
static AVL *LR(AVL *p) {
    AVL *pl = p->left;
    AVL *plr = pl->right;
    pl->right = plr->left;
    p->left = plr->right;
    plr->left = pl;
    plr->right = p;
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);
    return plr;
}
static AVL *RL(AVL *p) {
    AVL *pr = p->right;
    AVL *prl = pr->left;
    pr->left = prl->right;
    p->right = prl->left;
    prl->right = pr;
    prl->left = p;
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);
    return prl;
}

static AVL *insert(AVL *p, char *key) {
    AVL *new = NULL;
    if (p == NULL) {
        new = (AVL *)malloc(sizeof(AVL));
        new->string = strdup(key);
        new->height = 1;
        new->left = new->right = NULL;
        return new;
    }
    int a = strcmp(key, p->string);
    if (a > 0) {
        p->right = insert(p->right, key);
    } else {
        p->left = insert(p->left, key);
    }
    p->height = NodeHeight(p);
    if (balanceFactor(p) == 2 && balanceFactor(p->left) == 1) {
        return LL(p);
    } else if (balanceFactor(p) == 2 && balanceFactor(p->left) == -1) {
        return LR(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->right) == -1) {
        return RR(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->right) == 1) {
        return RL(p);
    }

    return p;
}
static AVL *findNode(AVL *root, const char *value) {
    while (root) {
        int a = strcmp(root->string, value);
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

void testAVL(int data, int search, char *filename, FILE *filePtr, FILE *searchPtr) {
    struct timeval tv;
    struct timeval start_tv;
    double elapsed = 0.0;

    gettimeofday(&start_tv, NULL);
    AVL *node = NULL;
    char buffer[1024];

    for (size_t i = 0; i < data; i++) {
        fscanf(filePtr, "%1023s", buffer);
        node = insert(node, buffer);
    }
    gettimeofday(&tv, NULL);
    elapsed = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    printf("%f\n", elapsed);
    gettimeofday(&start_tv, NULL);

    for (size_t i = 0; i < search; i++) {
        fscanf(searchPtr, "%1023s", buffer);
        findNode(node, buffer);
    }
    gettimeofday(&tv, NULL);
    free(node);
    elapsed = ((tv.tv_sec - start_tv.tv_sec) + (tv.tv_usec - start_tv.tv_usec) / 1000000.0);
    printf("%f\n", elapsed);
}
