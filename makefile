all: main.o lists.o library.o
	clang -o main main.o lists.o library.o

main.o: main.c lists.h
	clang -c main.c 

lists.o: lists.c
	clang -c lists.c 

library.o: library.c library.h
	clang -c library.c

clean:
	rm -rf *.o

run:
	./main