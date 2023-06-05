CXX = g++
CXX_FLAGS = -Wall -Wextra -pedantic -Werror -fsanitize=undefined -std=c++2a

all: main leaks tests

main:
	$(CXX) $(CXX_FLAGS) -c main.cpp Player.cpp Spike.cpp BoxCollider.cpp Level.cpp Game.cpp
	$(CXX) $(CXX_FLAGS) main.o Player.o Spike.o BoxCollider.o Level.o Game.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system 
	./sfml-app 

leaks:
	valgrind --leak-check=yes ./sfml-app

tests:


clean:
	rm *.o sfml-app Game