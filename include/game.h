#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <time.h>
#include <vector>
#include <deque>
#include "raylib.h"

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 900
#define SPACING 30

class Game {
    public:
        Game();
        ~Game();

        void run();
    private:
        void setup();
        void handleKeyPress();
        void updateSnakePos();
        void handleFruitCollision();
        void generateFruit();

        bool gameOver { false };

        std::vector<int> verticalLines;
        std::vector<int> horizontalLines;

        std::deque<std::pair<int, int>> snake;

        enum Direction {
            STOP,
            LEFT,
            RIGHT,
            UP,
            DOWN,
        };

        Direction snakeDirection { STOP };

        int fruitX, fruitY;

        double lastMoveTime { 0.0 };
        const double moveDelay { 0.2 };
};

#endif