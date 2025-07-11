#include "../include/Game.h"

Game::Game() {
    srand(time(0));
    setup();
}

Game::~Game() {

}

void Game::run() {
    const int halfSpacing = SPACING / 2;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        double currentTime = GetTime();

        handleKeyPress();
        if (currentTime - lastMoveTime >= moveDelay) {
            updateSnakePos();
            lastMoveTime = currentTime;
        }

        BeginDrawing();
            ClearBackground(BLACK);
            for (int i = SPACING; i <= SCREEN_WIDTH - SPACING; i += SPACING) {
                DrawLine(i, 0, i, SCREEN_HEIGHT, GRAY);
                DrawLine(0, i, SCREEN_WIDTH, i, GRAY);
            }
            
            DrawCircle(snake[0].x + halfSpacing, snake[0].y + halfSpacing, SPACING - 18, GREEN);
            DrawCircle(fruitX + halfSpacing, fruitY + halfSpacing, SPACING - 18, RED);
            
        EndDrawing();
    }

    CloseWindow();
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

void Game::handleKeyPress() {
    if (IsKeyDown(KEY_RIGHT)) {
        playerDirection = RIGHT;
    }
    if (IsKeyDown(KEY_LEFT)) {
        playerDirection = LEFT;
    }
    if (IsKeyDown(KEY_UP)) {
        playerDirection = UP;
    }
    if (IsKeyDown(KEY_DOWN)) {
        playerDirection = DOWN;
    }
}

void Game::updateSnakePos() {
    if (playerDirection == RIGHT) {
        for (int i = 0; i < snakeLength; i++) {
            snake[i].x += SPACING;
        }
    }
    if (playerDirection == LEFT) {
        for (int i = 0; i < snakeLength; i++) {
            snake[i].x -= SPACING;
        }
    }
    if (playerDirection == UP) {
        for (int i = 0; i < snakeLength; i++) {
            snake[i].y -= SPACING;
        }
    }
    if (playerDirection == DOWN) {
        for (int i = 0; i < snakeLength; i++) {
            snake[i].y += SPACING;
        }
    }
}