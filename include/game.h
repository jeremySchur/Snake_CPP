#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <time.h>
#include <vector>
#include <deque>
#include <unordered_set>
#include "raylib.h"

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 900
#define SPACING 30

struct pair_hash {
    std::size_t operator()(const std::pair<int, int>& p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};

class Game {
    public:
        Game();
        ~Game();

        void run();
    private:
        void setup();
        void handleKeyPress();
        void extendSnake(int x, int y);
        void updateSnakePos();
        void handleFruitCollision();
        void generateFruit();
        bool snakeCollision();

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

        std::pair<int, int> fruitPos;
        std::unordered_set<std::pair<int, int>, pair_hash> emptySpaces;

        double lastMoveTime { 0.0 };
        const double moveDelay { 0.2 };
};

#endif