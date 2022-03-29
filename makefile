makefile: 

compile: main.cpp
	g++ -Wall -Werror -std=c++17 -g main.cpp

run: main.cpp
	./a.out
