#ifndef QUEENBEE_H
#define QUEENBEE_H

#include "Insect.h"

// 定义 QueenBee 类，继承自 Insect
class QueenBee : public Insect {
public:
    // 构造函数
    QueenBee(const Position& pos) : Insect(pos, "QueenBee") {}

    // 实现 QueenBee 的可移动规则
    std::vector<Position> getAvailableMoves(Board* board) override;
};

#endif // QUEENBEE_H