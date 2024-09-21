#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <utility> // for std::pair

class Snake {
public:
    Snake(int startX, int startY);
    void move();
    void grow();
    void setDirection(char newDirection);
    bool checkCollision(int width, int height);
    const std::vector<std::pair<int, int>>& getBody() const;

private:
    std::vector<std::pair<int, int>> body;
    char direction;
};

#endif
