CC = g++

CFLAGS = -c -Wall

all : task_1

task_1 : main.o line_rectangle.o
	$(CC) main.o line_rectangle.o -o task_1

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

line_rectangle.o: line_rectangle.cpp
	$(CC) $(CFLAGS) line_rectangle.cpp

clean: 
	del *.o *.gch

# higher for windows, lower for linux. Uncomment and comment the necessary things.

#clean:
#	rm -rf *.o *.gch

