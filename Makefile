output: main.o game.o
	g++ main.o game.o -o snake

main.o:
	g++ -c src/main.cpp

game.o:
	g++ -c src/game.cpp

clean:
	del snake.exe
	del main.o
	del game.o