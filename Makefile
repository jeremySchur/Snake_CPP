CXX = g++
CXXFLAGS = -std=c++17 -Iraylib/src
LDFLAGS = raylib/src/libraylib.a

output: main.o game.o
	$(CXX) main.o game.o -o snake $(LDFLAGS)

main.o:
	$(CXX) $(CXXFLAGS) -c src/main.cpp

game.o:
	$(CXX) $(CXXFLAGS) -c src/game.cpp

clean:
	del snake.exe
	del main.o
	del game.o