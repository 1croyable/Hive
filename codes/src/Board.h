#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Position.h"
#include "Insect.h"  // 确保包含了 Insect.h 文件
#include "Position.h"

class Board {
public:
    Board();
    std::vector<Position> getAdjacentPositions(const Position& pos);
    bool isPositionFree(const Position& pos);
    void placePiece(Insect* insect, const Position& pos);
    void movePiece(Insect* insect, const Position& newPos);

private:
    std::vector<std::vector<Insect*>> grid;  // 使用 Insect* 的完整定义
};

#endif // BOARD_H