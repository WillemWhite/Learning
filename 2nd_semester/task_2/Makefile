CC = g++

CFLAGS = -c -Wall

all : task_2

task_2 : main.o polynomial.o
	$(CC) main.o polynomial.o -o task_2

main.o: main.cpp pol.h
	$(CC) $(CFLAGS) main.cpp pol.h

polynomial.o: polynomial.cpp
	$(CC) $(CFLAGS) polynomial.cpp

clean: 
	del *.o *.gch