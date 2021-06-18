# makefile, test01
t: main.o swap.o printfs.o
	gcc main.o swap.o printfs.o -lm -o t

swap.o: swap.c
	gcc -c swap.c -o swap.o

printfs.o: printfs.c
	gcc -c printfs.c -o printfs.o

main.o: main.c
	gcc -c main.c -o main.o

.PHONY:
clean:
	rm -rf main.o swap.o printfs.o
