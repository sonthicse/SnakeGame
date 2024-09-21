#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"

class Game {
public:
    Game(int width, int height);
    void start();

private:
    void drawGame();
    void update();

    Snake snake;
    Food food;
    int width, height;
    int score;
    bool isOver;
};

#include "../src/Game.cpp"

#endif
