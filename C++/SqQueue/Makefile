# makefile
CC := g++
OBJ = Queue.o
SRC = Queue.cpp
INC = /home/xudong/C/C++/SqQueue

t: main.o $(OBJ)
	$(CC) main.o $(OBJ) -o t

$(OBJ): $(SRC)
	$(CC) -c $(SRC) -o $(OBJ) -I $(INC)

main.o: main.cpp
	$(CC) -c main.cpp -o main.o


.PHONY:
clean:
	rm -rf mian.o $(OBJ) t
