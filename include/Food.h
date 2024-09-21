#ifndef FOOD_H
#define FOOD_H

class Food {
public:
    // Constructor khởi tạo thức ăn với vị trí ngẫu nhiên ban đầu
    Food(int width, int height);

    // Sinh vị trí thức ăn ngẫu nhiên không trùng với rắn
    void generateFood(int width, int height);

    // Getter cho tọa độ của thức ăn
    int getX() const;
    int getY() const;

    // Lấy vị trí của thức ăn dưới dạng cặp tọa độ
    std::pair<int, int> getPosition() const;

    // Vẽ thức ăn tại vị trí hiện tại
    void draw() const;

private:
    int x; // Tọa độ X của thức ăn
    int y; // Tọa độ Y của thức ăn
};

#endif
