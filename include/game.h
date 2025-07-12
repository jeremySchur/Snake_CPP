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

struct SnakeComponent {
    SnakeComponent(int xPos, int yPos) : x(xPos), y(yPos) { }

    int x { -1 };
    int y { -1 };
};

class Game {
    public:
        Game();
        ~Game();

        void run();
    private:
        void setup();
        void handleKeyPress();
        void updateSnakePos();

        bool gameOver { false };

        std::vector<int> verticalLines;
        std::vector<int> horizontalLines;

        std::deque<SnakeComponent> snake;

        enum Direction {
            STOP,
            LEFT,
            RIGHT,
            UP,
            DOWN,
        };

        Direction snakeDirection { STOP };

        int fruitX, fruitY;
        int score { 0 };

        double lastMoveTime { 0.0 };
        const double moveDelay { 0.2 };
};

#endif