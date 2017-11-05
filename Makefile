CC=g++
CFLAGS=-c -Wall -std=c++14

all: eduproject.exe clean

eduproject.exe: main.o
	$(CC) main.o -o make-build/eduproject.exe

main.o: src
	$(CC) -c eduproject/main.cpp

clean:
	del *o eduproject.exe