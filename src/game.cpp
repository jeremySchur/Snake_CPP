#include "../include/Game.h"

Game::Game() {
    srand(time(0));
    setup();
}

Game::~Game() {

}

void Game::setup() {
    for (int i = 0; i <= screenWidth; i += spacing) {
        verticalLines.push_back(i);
    }
    for (int i = 0; i <= screenHeight; i += spacing) {
        horizontalLines.push_back(i);
    }

    const int vSize = verticalLines.size();
    const int hSize = horizontalLines.size();

    playerX = verticalLines[vSize / 2];
    playerY = horizontalLines[hSize / 2];
    fruitX = verticalLines[rand() % vSize];
    fruitY = horizontalLines[rand() % hSize];
}

void Game::run() {
    InitWindow(screenWidth, screenHeight, "Snake");

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            for (int i = spacing; i <= screenWidth - spacing; i += spacing) {
                DrawLine(i, 0, i, screenHeight, GRAY);
                DrawLine(0, i, screenWidth, i, GRAY);
            }
            
            const int halfSpacing = spacing / 2;
            const int fifthSpacing = spacing / 5;
            DrawCircle(playerX + halfSpacing, playerY + halfSpacing, spacing - 18, GREEN);
            DrawCircle(fruitX + halfSpacing, fruitY + halfSpacing, spacing - 18, RED);
            
        EndDrawing();
    }

    CloseWindow();
}