CC = g++
CFLAGS = -Wall -g -Wextra

main.exe: main.o SHA.o
	$(CC) $(CFLAGS) -o main.exe main.o SHA.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

SHA.o: 
	$(CC) $(CFLAGS) -c crypto/SHA.cpp

clean:
	@echo Cleaning up...
	@rm *.o *.exe

# target: dependencies
# 	action