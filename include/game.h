#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <time.h>
#include "raylib.h"

class Game {
    public:
        Game();
        ~Game();

        void run();
    private:
        bool gameOver { false };

        const int screenWidth { 900 };
        const int screenHeight { 900 };
        const int spacing { 30 };

        int playerX, playerY, fruitX, fruitY;
        int score { 0 };
        
        enum Direction {
            STOP,
            LEFT,
            RIGHT,
            UP,
            DOWN,
        };

        Direction dir { STOP };
};

#endif