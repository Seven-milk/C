# makefile, test01
t: main.o LinkList.o
	g++ main.o LinkList.o -o t

LinkList.o: LinkList.cpp
	g++ -c LinkList.cpp -o LinkList.o -I LinkList.h

main.o: main.cpp
	g++ -c main.cpp -o main.o


.PHONY:
clean:
	rm -rf main.o LinkList.o t
