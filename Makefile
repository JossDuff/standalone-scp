CC = g++
CFLAGS = -Wall -g

main.exe: main.o
	$(CC) $(CFLAGS) -o main.exe main.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	@echo Cleaning up...
	@rm *.o *.exe