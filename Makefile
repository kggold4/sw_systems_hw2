# variables
CC = gcc
WGC = -Wall -g -c

# main command
all: main

main: main.o myBank.o
	$(CC) -Wall myBank.o main.o -o main

# main.o file
main.o: main.c myBank.h
	$(CC) $(WGC) main.c

# myBank.o file
myBank.o: myBank.c
	$(CC) $(WGC) myBank.c

# removing all .o, .out and main (exeute) files
clean:
	rm -f *.o *.out *.a *.so main