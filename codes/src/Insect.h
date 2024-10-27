#ifndef INSECT_H
#define INSECT_H

#include <string>   // 确保包含 string 类型的定义
#include <vector>
#include "Position.h"

class Board;  // 前置声明 Board 类

class Insect {
public:
    // 构造函数
    Insect(const Position& pos, const std::string& type) : position(pos), type(type) {}

    // 虚析构函数
    virtual ~Insect() {}

    // 纯虚函数：每种昆虫有自己可移动的位置规则，派生类需要实现它
    virtual std::vector<Position> getAvailableMoves(Board* board) = 0;

    // 设置昆虫的位置
    void setPosition(const Position& pos) { position = pos; }

    // 获取昆虫的位置
    Position getPosition() const { return position; }

    // 获取昆虫的类型
    std::string getType() const { return type; }

protected:
    Position position;  // 昆虫的当前位置
    std::string type;   // 昆虫的类型，例如 "QueenBee" 等
};

#endif // INSECT_H