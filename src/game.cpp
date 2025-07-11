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
            if (playerDirection != STOP) {
                updateSnakePos();
            }
            lastMoveTime = currentTime;
        }

        BeginDrawing();
            ClearBackground(BLACK);
            for (int i = SPACING; i <= SCREEN_WIDTH - SPACING; i += SPACING) {
                DrawLine(i, 0, i, SCREEN_HEIGHT, GRAY);
                DrawLine(0, i, SCREEN_WIDTH, i, GRAY);
            }
            
            for (int i = 0; i < snakeLength; i++) {
                DrawCircle(snake[i].x + halfSpacing, snake[i].y + halfSpacing, SPACING - 18, GREEN);
            }
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
    for (int i = snakeLength - 1; i > 0; i--) {
        snake[i].x = snake[i-1].x;
        snake[i].y = snake[i-1].y;
    }

    if (playerDirection == RIGHT) {
        snake[0].x += SPACING;
    }
    if (playerDirection == LEFT) {
        snake[0].x -= SPACING;
    }
    if (playerDirection == UP) {
        snake[0].y -= SPACING;
    }
    if (playerDirection == DOWN) {
        snake[0].y += SPACING;
    }
}