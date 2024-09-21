#include "../include/Snake.h"
#include <iostream>

Snake::Snake(int startX, int startY) {
    body.push_back({startX, startY});
    direction = 'R'; // Mặc định di chuyển sang phải
}

void Snake::move() {
    // Lấy vị trí đầu hiện tại của rắn
    auto head = body.front();
    int x = head.first;
    int y = head.second;

    // Di chuyển theo hướng hiện tại
    switch (direction) {
        case 'U': y--; break;
        case 'D': y++; break;
        case 'L': x--; break;
        case 'R': x++; break;
    }

    // Di chuyển các phần tử của thân rắn
    for (int i = body.size() - 1; i > 0; --i) {
        body[i] = body[i - 1];
    }
    body[0] = {x, y};
}

void Snake::grow() {
    // Thêm phần tử mới vào thân rắn
    body.push_back(body.back());
}

void Snake::setDirection(char newDirection) {
    direction = newDirection;
}

bool Snake::checkCollision(int width, int height) {
    // Kiểm tra va chạm với biên màn hình
    auto head = body.front();
    if (head.first < 0 || head.first >= width || head.second < 0 || head.second >= height) {
        return true;
    }

    // Kiểm tra va chạm với thân rắn
    for (size_t i = 1; i < body.size(); ++i) {
        if (body[0] == body[i]) {
            return true;
        }
    }

    return false;
}

const std::vector<std::pair<int, int>>& Snake::getBody() const {
    return body;
}

char Snake::getDirection() const { return direction; }