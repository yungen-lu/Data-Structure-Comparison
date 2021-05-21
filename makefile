CC = gcc
# CXX = include-what-you-use
util.o: util/util.c util/util.h header/header.h
	$(CC) -c util/util.c -o util.o

LinkedList.o: LinkedList/LinkedList.c LinkedList/LinkedList.h
	$(CC) -c LinkedList/LinkedList.c -o LinkedList.o

Array.o: Array/Array.c Array/Array.h
	$(CC) -c Array/Array.c -o Array.o

ArrayWithBinarySearch.o: ArrayWithBinarySearch/ArrayWithBinarySearch.c ArrayWithBinarySearch/ArrayWithBinarySearch.h 
	$(CC) -c ArrayWithBinarySearch/ArrayWithBinarySearch.c -o ArrayWithBinarySearch.o

BinarySearchTree.o: BinarySearchTree/BinarySearchTree.c BinarySearchTree/BinarySearchTree.h
	$(CC) -c BinarySearchTree/BinarySearchTree.c -o BinarySearchTree.o

Hash.o: Hash/Hash.h Hash/Hash.c
	$(CC) -c Hash/Hash.c -o Hash.o

AVL.o: AVL/AVL.h AVL/AVL.c
	$(CC) -c AVL/AVL.c -o AVL.o

main: main.c util.o Array.o BinarySearchTree.o LinkedList.o BinarySearchTree.o ArrayWithBinarySearch.o Hash.o AVL.o
	gcc main.c util.o Array.o BinarySearchTree.o LinkedList.o ArrayWithBinarySearch.o Hash.o AVL.o -o main
cleanMain:
	rm -rf main
cleanL:
	rm -rf  LinkedList.o
cleanA:
	rm -rf Array.o
cleanABS:
	rm -rf  ArrayWithBinarySearch.o
cleanBST:
	rm -rf BinarySearchTree.o
cleanH:
	rm -rf Hash.o
cleanAVL:
	rm -rf AVL.o
cleanU:
	rm -rf util.o
cleanALL: cleanL cleanA cleanABS cleanBST cleanH cleanU cleanAVL cleanMain
