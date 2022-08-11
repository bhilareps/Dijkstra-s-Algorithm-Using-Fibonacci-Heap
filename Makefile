run   : fibheap.o graph.o minheap.o main.o 
	gcc -o fibheap *.o
clean :
	del *.o
fibheap.o : fibheap.c fibheap.h
	gcc -c fibheap.c 
minheap.o : MinFibHeap/minheap.c MinFibHeap/minheap.h
	gcc -c MinFibHeap/minheap.c
graph.o : graph.c graph.h 
	gcc -c graph.c
main.o: main.c
	gcc -c main.c

