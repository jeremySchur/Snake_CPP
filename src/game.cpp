#include "../include/Game.h"

Game::Game() {
    playerX = screenWidth / 2;
    playerY = screenHeight / 2;
    fruitX = rand() % screenWidth;
    fruitY = rand() % screenHeight;
}

Game::~Game() {

}

void Game::run() {
    srand(time(0));

    InitWindow(screenWidth, screenHeight, "Snake");

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            for (int i = spacing; i <= screenWidth - spacing; i += spacing) {
                DrawLine(i, 0, i, screenHeight, GRAY);
                DrawLine(0, i, screenWidth, i, GRAY);
            }

            DrawRectangle(playerX + 1, playerY + 2, spacing - 4, spacing - 4, GREEN);
            DrawCircle(fruitX + 2, fruitY - 1, spacing - 18, RED);
            
        EndDrawing();
    }

    CloseWindow();
}