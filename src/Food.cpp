#include "../include/Food.h"
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

Food::Food(int width, int height) {
    // Khởi tạo random seed cho rand()
    std::srand(std::time(0));
    generateFood(width, height);
}

void Food::generateFood(int width, int height) {
    // Sinh vị trí thức ăn ngẫu nhiên trong phạm vi của màn hình
    x = rand() % width;
    y = rand() % height;
}

int Food::getX() const {
    return x;
}

int Food::getY() const {
    return y;
}

std::pair<int, int> Food::getPosition() const {
    return std::make_pair(x, y);
}

void Food::draw() const {
    // Vẽ thức ăn tại vị trí (x, y)
    // Trong game logic, thức ăn sẽ được hiển thị trong hàm vẽ chính
    std::cout << "*";
}
