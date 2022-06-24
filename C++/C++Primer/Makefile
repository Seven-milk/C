# makefile, test01
t: main.o
	g++ main.o -o t

main.o: main.cpp
	g++ -c main.cpp -o main.o

.PHONY:
clean:
	rm -rf main.o t
