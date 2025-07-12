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
            if (snakeDirection != Direction::STOP) {
                updateSnakePos();
            }
            lastMoveTime = currentTime;
        }

        handleFruitCollision();

        BeginDrawing();
            ClearBackground(BLACK);
            for (int i = SPACING; i <= SCREEN_WIDTH - SPACING; i += SPACING) {
                DrawLine(i, 0, i, SCREEN_HEIGHT, GRAY);
                DrawLine(0, i, SCREEN_WIDTH, i, GRAY);
            }
            
            for (int i = 0; i < snake.size(); i++) {
                DrawCircle(snake.at(i).first + halfSpacing, snake.at(i).second + halfSpacing, SPACING - 18, GREEN);
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

    const int midPoint = SPACING / 2;

    snake.push_back(std::pair<int, int>(verticalLines[midPoint], horizontalLines[midPoint]));
    generateFruit();
}

void Game::handleKeyPress() {
    if (IsKeyDown(KEY_RIGHT)) {
        snakeDirection = Direction::RIGHT;
    }
    if (IsKeyDown(KEY_LEFT)) {
        snakeDirection = Direction::LEFT;
    }
    if (IsKeyDown(KEY_UP)) {
        snakeDirection = Direction::UP;
    }
    if (IsKeyDown(KEY_DOWN)) {
        snakeDirection = Direction::DOWN;
    }
}

void Game::updateSnakePos() {
    std::pair<int, int> front = snake.front();

    if (snakeDirection == Direction::RIGHT) {
        snake.push_front(std::pair<int, int>(front.first + SPACING, front.second));
    }
    if (snakeDirection == Direction::LEFT) {
        snake.push_front(std::pair<int, int>(front.first - SPACING, front.second));
    }
    if (snakeDirection == Direction::UP) {
        snake.push_front(std::pair<int, int>(front.first, front.second - SPACING));
    }
    if (snakeDirection == Direction::DOWN) {
        snake.push_front(std::pair<int, int>(front.first, front.second + SPACING));
    }

    snake.pop_back();
}

void Game::handleFruitCollision() {
    std::pair<int, int> front = snake.front();

    if (front.first == fruitX && front.second == fruitY) {
        if (snakeDirection == Direction::RIGHT) {
            snake.push_front(std::pair<int, int>(front.first + SPACING, front.second));
        }
        if (snakeDirection == Direction::LEFT) {
            snake.push_front(std::pair<int, int>(front.first - SPACING, front.second));
        }
        if (snakeDirection == Direction::UP) {
            snake.push_front(std::pair<int, int>(front.first, front.second - SPACING));
        }
        if (snakeDirection == Direction::DOWN) {
            snake.push_front(std::pair<int, int>(front.first, front.second + SPACING));
        }

        generateFruit();
    }
}

void Game::generateFruit() {
    const int vSize = verticalLines.size();
    const int hSize = horizontalLines.size();

    fruitX = verticalLines[rand() % vSize];
    fruitY = horizontalLines[rand() % hSize];
}
