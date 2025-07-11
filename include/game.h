#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <time.h>
#include <vector>
#include "raylib.h"

class Game {
    public:
        Game();
        ~Game();

        void setup();
        void run();
    private:
        bool gameOver { false };

        const int screenWidth { 900 };
        const int screenHeight { 900 };
        const int spacing { 30 };

        std::vector<int> verticalLines;
        std::vector<int> horizontalLines;

        int playerX, playerY, fruitX, fruitY;
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