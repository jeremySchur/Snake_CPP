#include "../include/Game.h"

Game::Game() {
    srand(time(0));
    setup();
}

Game::~Game() {

}

void Game::setup() {
    for (int i = 0; i <= SCREEN_WIDTH; i += SPACING) {
        verticalLines.push_back(i);
    }
    for (int i = 0; i <= SCREEN_HEIGHT; i += SPACING) {
        horizontalLines.push_back(i);
    }

    const int vSize = verticalLines.size();
    const int hSize = horizontalLines.size();

    snake[0] = SnakeComponent(verticalLines[vSize / 2], horizontalLines[hSize / 2]);
    fruitX = verticalLines[rand() % vSize];
    fruitY = horizontalLines[rand() % hSize];
}

void Game::run() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake");

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            for (int i = SPACING; i <= SCREEN_WIDTH - SPACING; i += SPACING) {
                DrawLine(i, 0, i, SCREEN_HEIGHT, GRAY);
                DrawLine(0, i, SCREEN_WIDTH, i, GRAY);
            }
            
            const int halfSpacing = SPACING / 2;
            const int fifthSpacing = SPACING / 5;
            DrawCircle(snake[0].x + halfSpacing, snake[0].y + halfSpacing, SPACING - 18, GREEN);
            DrawCircle(fruitX + halfSpacing, fruitY + halfSpacing, SPACING - 18, RED);
            
        EndDrawing();
    }

    CloseWindow();
}