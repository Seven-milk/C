# makefile, test01
t: main.o power.o
	gcc main.o power.o -lm -o t

power.o: power.c
	gcc -c power.c -o power.o

main.o: main.c
	gcc -c main.c -o main.o

.PHONY:
clean:
	rm -rf main.o power.o
