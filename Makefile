CC = g++
CFLAGS = -Wall -Wextra -std=c++11
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: Hexa

Hexa: hexa.o main.o
	$(CC) $(CFLAGS) hexa.o main.o -o Hexa $(SFML_FLAGS)

hexa.o: hexa.cpp hexa.hpp
	$(CC) $(CFLAGS) -c hexa.cpp

main.o: main.cpp hexa.hpp
	$(CC) $(CFLAGS) -c main.cpp

lint:
	cpplint --filter=-build/include_what_you_use *.cpp *.hpp

clean:
	rm -f Hexa *.o
