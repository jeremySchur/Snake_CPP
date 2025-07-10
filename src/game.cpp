#include "../include/Game.h"
#include "raylib.h"

Game::Game() {
    playerX = screenWidth / 2;
    playerY = screenHeight / 2;
    fruitX = rand() % screenWidth;
    fruitY = rand() % screenHeight;
}

Game::~Game() {

}

void Game::run() {
    InitWindow(800, 400, "Snake");

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
}