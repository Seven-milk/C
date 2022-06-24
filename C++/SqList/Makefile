# makefile, test01
t: main.o LinearList.o
	g++ main.o LinearList.o -o t

linearlist.o: linearlist.cpp
	g++ -c LinearList.cpp -o LinearList.o -I LinearList.h

main.o: main.cpp
	g++ -c main.cpp -o main.o


.PHONY:
clean:
	rm -rf main.o LinearList.o
