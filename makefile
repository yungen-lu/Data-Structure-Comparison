util.o: util/util.c util/util.h header/header.h
	gcc -c util/util.c -o util.o

LinkedList.o: LinkedList/LinkedList.c LinkedList/LinkedList.h
	gcc -c LinkedList/LinkedList.c -o LinkedList.o

Array.o: Array/Array.c Array/Array.h
	gcc -c Array/Array.c -o Array.o

ArrayWithBinarySearch.o: ArrayWithBinarySearch/ArrayWithBinarySearch.c ArrayWithBinarySearch/ArrayWithBinarySearch.h 
	gcc -c ArrayWithBinarySearch/ArrayWithBinarySearch.c -o ArrayWithBinarySearch.o

BinarySearchTree.o: BinarySearchTree/BinarySearchTree.c BinarySearchTree/BinarySearchTree.h
	gcc -c BinarySearchTree/BinarySearchTree.c -o BinarySearchTree.o

Hash.o: Hash/Hash.h Hash/Hash.c
	gcc -c Hash/Hash.c -o Hash.o

main: main.c util.o Array.o BinarySearchTree.o LinkedList.o BinarySearchTree.o ArrayWithBinarySearch.o Hash.o
	gcc main.c util.o Array.o BinarySearchTree.o LinkedList.o ArrayWithBinarySearch.o Hash.o -o main

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
cleanU:
	rm -rf util.o
cleanALL: cleanL cleanA cleanABS cleanBST cleanH cleanU cleanMain
