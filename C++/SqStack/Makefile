# makefile
CC := g++

t: main.o Stack.o
	$(CC) main.o Stack.o -o t

Stack.o: Stack.cpp
	$(CC) -c Stack.cpp -o Stack.o -I Stack.h

main.o: main.cpp
	$(CC) -c main.cpp -o main.o


.PHONY:
clean:
	rm -rf mian.o Stack.o t
