#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "AVL/AVL.h"
#include "Array/Array.h"
#include "ArrayWithBinarySearch/ArrayWithBinarySearch.h"
#include "BinarySearchTree/BinarySearchTree.h"
#include "Hash/Hash.h"
#include "LinkedList/LinkedList.h"
#include "util/util.h"
int main(int argc, char* argv[]) {
    char* filename = (char*)calloc(64, sizeof(char));
    char* searchName = (char*)calloc(64, sizeof(char));
    int ret;
    const char* optstring = "d:q:BbalhAgf:s:";
    struct option opts[] = {{"data", 1, NULL, 'd'},       {"query", 1, NULL, 'q'}, {"bst", 0, NULL, 'B'},
                            {"bs", 0, NULL, 'b'},         {"arr", 0, NULL, 'a'},   {"ll", 0, NULL, 'l'},
                            {"hash", 0, NULL, 'h'},       {"avl", 0, NULL, 'A'},   {"filename", 1, NULL, 'f'},
                            {"searchname", 1, NULL, 's'}, {"gen", 0, NULL, 'g'}

    };
    int data;
    int search;
    int type;
    while ((ret = getopt_long(argc, argv, optstring, opts, NULL)) != -1) {
        switch (ret) {
            case 'd':
                sscanf(optarg, "%d", &data);
                break;
            case 'q':
                sscanf(optarg, "%d", &search);
                break;
            case 'B':
                type = Bst;
                break;
            case 'b':
                type = Bs;
                break;
            case 'a':
                type = Arr;
                break;
            case 'l':
                type = Ll;
                break;
            case 'h':
                type = Hash;
                break;
            case 'A':
                type = Avl;
                break;
            case 'f':
                sscanf(optarg, "%s", filename);
                break;
            case 's':
                sscanf(optarg, "%s", searchName);
                break;
            case 'g':
                type = Gen;
                break;
            default:
                printf("------\n");
        }
    }
    FILE* f1;
    FILE* f2;
    if (type <= Avl && type >= Bst) {
        f1 = openFile(filename);
        f2 = openFile(searchName);
    }

    switch (type) {
        case Bst:
            testBST(data, search, f1, f2);
            break;
        case Hash:
            testHASH(data, search, f1, f2);
            break;
        case Ll:
            testLL(data, search, f1, f2);
            break;
        case Bs:
            testBS(data, search, f1, f2);
            break;
        case Arr:
            testARR(data, search, f1, f2);
            break;
        case Avl:
            testAVL(data, search, f1, f2);
            break;
        case Gen:
            randWriteStr(100, data, filename);
            randWriteStr(100, search, searchName);
            break;
        default:
            printf("enter type\n");
            break;
    }
    if (type <= Avl && type >= Bst) {
        fclose(f1);
        fclose(f2);
    }
}
