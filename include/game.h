#ifndef GAME_H
#define GAME_H

class Game {
    public:
        Game();
        ~Game();

        bool isGameOver();
    private:
        bool gameOver { false };
};

#endif