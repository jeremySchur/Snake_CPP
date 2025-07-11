#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <time.h>
#include <vector>
#include "raylib.h"

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 900
#define SPACING 30

struct SnakeComponent {
    SnakeComponent() { }
    SnakeComponent(int xPos, int yPos) : x(xPos), y(yPos) { }

    int x = 0, y = 0;
};

class Game {
    public:
        Game();
        ~Game();

        void setup();
        void run();
    private:
        bool gameOver { false };

        std::vector<int> verticalLines;
        std::vector<int> horizontalLines;

        SnakeComponent snake[SPACING * SPACING];
        int snakeLength { 1 };

        int fruitX, fruitY;
        int score { 0 };
        
        enum Direction {
            STOP,
            LEFT,
            RIGHT,
            UP,
            DOWN,
        };

        Direction playerDirection { STOP };
};

#endif