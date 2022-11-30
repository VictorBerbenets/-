CC = g++

CFLAGS =-c -Wall -Wextra

all : Kvadr

Kvadr : main.o Functions.o 
	$(CC) $^ -o Kvadr

main.o : main.cpp
	$(CC) $(CFLAGS) $^

Functions.o : Functions.cpp
	$(CC) $(CFLAGS) $^

clean:
	rm -rf * .o Kvadr