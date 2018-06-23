#Declaring variables for the Makefile

CC=g++


CFLAGS=-c -Wall

all: filem

filem: a2.o
	$(CC) -pthread a2.cpp a2.h -o filem

a2.o: a2.cpp
	$(CC) $(CFLAGS) a2.cpp

clean:
	rm -rf *o filem
