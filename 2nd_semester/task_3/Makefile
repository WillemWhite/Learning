CC = g++

CFLAGS = -c -Wall

all : task_3

task_3 : main.o parabola.o
	$(CC) main.o parabola.o -o task_3

main.o: main.cpp parb.h
	$(CC) $(CFLAGS) main.cpp parb.h

parabola.o: parabola.cpp
	$(CC) $(CFLAGS) parabola.cpp

clean: 
	del *.o *.gch

# higher for windows, lower for linux. Uncomment and comment the necessary things.

#clean:
#	rm -rf *.o *.gch