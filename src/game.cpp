#include "../include/Game.h"

Game::Game() {
    for (int i = 0; i <= SCREEN_WIDTH; i += SPACING) {
        verticalLines.push_back(i);
    }
    for (int i = 0; i <= SCREEN_HEIGHT; i += SPACING) {
        horizontalLines.push_back(i);
    }

    for (int i = 0; i < verticalLines.size(); i++) {
        for (int j = 0; j < horizontalLines.size(); j++) {
            emptySpaces.insert(std::pair<int, int>(verticalLines[i], horizontalLines[i]));
        }
    }
}

Game::~Game() {

}

void Game::run() {
    setup();

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

        if (snakeCollision()) {
            break;
        }

        BeginDrawing();
            ClearBackground(BLACK);
            for (int i = SPACING; i <= SCREEN_WIDTH - SPACING; i += SPACING) {
                DrawLine(i, 0, i, SCREEN_HEIGHT, GRAY);
                DrawLine(0, i, SCREEN_WIDTH, i, GRAY);
            }
            
            for (int i = 0; i < snake.size(); i++) {
                DrawCircle(snake.at(i).first + halfSpacing, snake.at(i).second + halfSpacing, SPACING - 18, GREEN);
            }
            DrawCircle(fruitPos.first + halfSpacing, fruitPos.second + halfSpacing, SPACING - 18, RED);
            
        EndDrawing();
    }

    while(!WindowShouldClose()) {
        BeginDrawing();
            DrawText("Game Over!", 180, (SCREEN_HEIGHT / 2) - 60, 100, WHITE);
        EndDrawing();
    }

    CloseWindow();
}

void Game::setup() {
    srand(time(0));
    
    const int midPoint = SPACING / 2;

    extendSnake(verticalLines[midPoint], horizontalLines[midPoint]);
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

void Game::extendSnake(int x, int y) {
    std::pair<int, int> space = std::pair<int, int>(x, y);

    snake.push_front(space);
    emptySpaces.erase(space);
}

void Game::updateSnakePos() {
    std::pair<int, int> front = snake.front();

    if (snakeDirection == Direction::RIGHT) {
        extendSnake(front.first + SPACING, front.second);
    }
    if (snakeDirection == Direction::LEFT) {
        extendSnake(front.first - SPACING, front.second);
    }
    if (snakeDirection == Direction::UP) {
        extendSnake(front.first, front.second - SPACING);
    }
    if (snakeDirection == Direction::DOWN) {
        extendSnake(front.first, front.second + SPACING);
    }

    std::pair<int, int> back = snake.back();

    snake.pop_back();
    emptySpaces.insert(back);
}

void Game::handleFruitCollision() {
    std::pair<int, int> front = snake.front();

    if (front.first == fruitPos.first && front.second == fruitPos.second) {
        if (snakeDirection == Direction::RIGHT) {
            extendSnake(front.first + SPACING, front.second);
        }
        if (snakeDirection == Direction::LEFT) {
            extendSnake(front.first - SPACING, front.second);
        }
        if (snakeDirection == Direction::UP) {
            extendSnake(front.first, front.second - SPACING);
        }
        if (snakeDirection == Direction::DOWN) {
            extendSnake(front.first, front.second + SPACING);
        }

        generateFruit();
    }
}

void Game::generateFruit() {
    int index = rand() % emptySpaces.size();

    auto it = emptySpaces.begin();
    std::advance(it, index);

    fruitPos = *it;
}

bool Game::snakeCollision() {
    std::pair<int, int> front = snake.front();

    if (front.first < 0 || front.first > SCREEN_WIDTH) {
        return true;
    }
    if (front.second < 0 || front.second > SCREEN_HEIGHT) {
        return true;
    }

    for (int i = 1; i < snake.size(); i++) {
        std::pair<int, int> current = snake.at(i);
        if (front.first == current.first && front.second == current.second) {
            return true;
        }
    }

    return false;
}
