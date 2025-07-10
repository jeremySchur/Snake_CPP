output: main.o game.o
	g++ main.o game.o -o snake

main.o:
	g++ -c src/main.cpp

game.o:
	g++ -c src/game.cpp
