#ifndef POSITION_H  // include guard
#define POSITION_H

class Position {
public:
    int x, y;

    // 构造函数
    Position(int x = 0, int y = 0) : x(x), y(y) {}

    // 运算符重载：判断两个位置是否相等
    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};

#endif // POSITION_H