#include <stdio.h>

#include "Array/Array.h"
#include "ArrayWithBinarySearch/ArrayWithBinarySearch.h"
#include "BinarySearchTree/BinarySearchTree.h"
#include "Hash/Hash.h"
#include "LinkedList/LinkedList.h"
#include "util/util.h"
int main(int argc, char* argv[]) {
    ARG* arg = parseArg(argv, argc);
    char* filename = "test.txt";
    char* searchName = "test-search.txt";
    randWriteStr(10, arg->data, filename);
    randWriteStr(10, arg->search, searchName);
    FILE* f1 = openFile(filename);
    FILE* f2 = openFile(searchName);

    switch (arg->type) {
        case Bst:
            testBST(arg->data, arg->search, filename, f1, f2);
            break;
        case Hash:
            testHASH(arg->data, arg->search, filename, f1, f2);
            break;
        case Ll:
            testLL(arg->data, arg->search, filename, f1, f2);
            break;
        case Bs:
            testBS(arg->data, arg->search, filename, f1, f2);
            break;
        case Arr:
            testARR(arg->data, arg->search, filename, f1, f2);
            break;
    }
}
