#include <getopt.h>
#include <stdio.h>

#include "Array/Array.h"
#include "ArrayWithBinarySearch/ArrayWithBinarySearch.h"
#include "BinarySearchTree/BinarySearchTree.h"
#include "Hash/Hash.h"
#include "LinkedList/LinkedList.h"
#include "util/util.h"
int main(int argc, char* argv[]) {
    char* filename = "test.txt";
    char* searchName = "test-search.txt";
    int ret;
    const char* optstring = "d:q:Bbalh";
    struct option opts[] = {{"data", 1, NULL, 'd'}, {"query", 1, NULL, 'q'}, {"bst", 0, NULL, 'B'},
                            {"bs", 0, NULL, 'b'},   {"arr", 0, NULL, 'a'},   {"ll", 0, NULL, 'l'},
                            {"hash", 0, NULL, 'h'}

    };
    int data, search;
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
            default:
                printf("------\n");
        }
    }
    randWriteStr(10, data, filename);
    randWriteStr(10, search, searchName);
    FILE* f1 = openFile(filename);
    FILE* f2 = openFile(searchName);

    switch (type) {
        case Bst:
            testBST(data, search, filename, f1, f2);
            break;
        case Hash:
            testHASH(data, search, filename, f1, f2);
            break;
        case Ll:
            testLL(data, search, filename, f1, f2);
            break;
        case Bs:
            testBS(data, search, filename, f1, f2);
            break;
        case Arr:
            testARR(data, search, filename, f1, f2);
            break;
    }
}
