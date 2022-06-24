# Makefile: test02
t: main.o
	gcc main.o -o t

main.o: main.c
	gcc -c main.c -o main.o

.PHONY:
clean:
	rm -rf main.o
