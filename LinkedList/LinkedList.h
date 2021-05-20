struct ll {
    char *string;
    struct ll *next;
};
typedef struct ll LinkedList;

void testLL(int data, int search, const char *fileName, const char *searchName);
