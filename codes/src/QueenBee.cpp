#include "QueenBee.h"
#include "Board.h"
// 实现 QueenBee 的可移动逻辑
std::vector<Position> QueenBee::getAvailableMoves(Board* board) {
    std::vector<Position> moves;

    // 示例：蜂后只能移动到周围的一个相邻格子
    std::vector<Position> possibleMoves = board->getAdjacentPositions(getPosition());

    // 检查每个相邻位置是否可以移动
    for (const auto& pos : possibleMoves) {
        if (board->isPositionFree(pos)) {
            moves.push_back(pos);
        }
    }

    return moves;
}