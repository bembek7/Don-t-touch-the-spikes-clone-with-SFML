CXX = g++
CXX_FLAGS = -Wall -Wextra -pedantic -Werror -fsanitize=undefined -std=c++2a

all: main tests clean

main:
	$(CXX) $(CXX_FLAGS) -c main.cpp Player.cpp
	$(CXX) $(CXX_FLAGS) main.o Player.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system 
	./sfml-app 

tests:


clean:
	rm main.o Player.o sfml-app