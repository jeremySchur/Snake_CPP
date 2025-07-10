#ifndef GAME_H
#define GAME_H

#include <iostream>

class Game {
    public:
        Game();
        ~Game();

        void run();
    private:
        bool gameOver { false };

        const int screenWidth { 20 };
        const int screenHeight { 20 };

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