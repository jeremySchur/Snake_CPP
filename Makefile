CXX = g++
CXXFLAGS = -std=c++17 -Iraylib/src
LDFLAGS = raylib/src/libraylib.a -lopengl32 -lgdi32 -lwinmm

all: run

output: main.o game.o
	$(CXX) main.o game.o -o snake $(LDFLAGS)

main.o:
	$(CXX) $(CXXFLAGS) -c src/main.cpp

game.o:
	$(CXX) $(CXXFLAGS) -c src/game.cpp

run: clean output
	snake.exe

clean:
	del snake.exe
	del main.o
	del game.o