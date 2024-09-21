#include "../include/Game.h"
#include <iostream>
#include <conio.h> // Windows, trên Linux dùng ncurses

Game::Game(int w, int h) : width(w), height(h), snake(w / 2, h / 2), food(w, h), score(0), isOver(false) {}

void Game::start() {
    while (!isOver) {
        if (_kbhit()) {
            char key = _getch();
            switch (key) {
                case 'w': snake.setDirection('U'); break;
                case 's': snake.setDirection('D'); break;
                case 'a': snake.setDirection('L'); break;
                case 'd': snake.setDirection('R'); break;
            }
        }

        update();
        drawGame();

        // Delay để game không chạy quá nhanh
        _sleep(200);
    }

    std::cout << "Game Over! Your score: " << score << std::endl;
}

void Game::update() {
    snake.move();

    if (snake.checkCollision(width, height)) {
        isOver = true;
    }

    if (snake.getBody().front() == food.getPosition()) {
        score += 10;
        snake.grow();
        food.generateFood(width, height);
    }
}

void Game::drawGame() {
    system("cls"); // Trên Linux dùng "clear"

    // Vẽ viền trên
    for (int i = 0; i < width + 2; ++i) std::cout << "#";
    std::cout << std::endl;

    // Vẽ thân màn hình trò chơi
    for (int y = 0; y < height; ++y) {
        std::cout << "#"; // Viền trái
        for (int x = 0; x < width; ++x) {
            if (std::find(snake.getBody().begin(), snake.getBody().end(), std::make_pair(x, y)) != snake.getBody().end()) {
                std::cout << "O"; // Rắn
            } else if (x == food.getX() && y == food.getY()) {
                std::cout << "*"; // Thức ăn
            } else {
                std::cout << " "; // Khoảng trống
            }
        }
        std::cout << "#" << std::endl; // Viền phải
    }

    // Vẽ viền dưới
    for (int i = 0; i < width + 2; ++i) std::cout << "#";
    std::cout << std::endl;

    std::cout << "Score: " << score << std::endl;
}
