#include <iostream>
#include "Board.h"
#include "QueenBee.h"

int main() {
    // 初始化棋盘
    Board board;

    // 创建一个蜂后对象，并将其放置在 (0, 0)
    QueenBee queen(Position(0, 0));
    board.placePiece(&queen, Position(0, 0));

    // 检查蜂后的位置是否成功放置
    if (!board.isPositionFree(Position(0, 0))) {
        std::cout << "QueenBee successfully placed at (0, 0)" << std::endl;
    }

    // 获取蜂后相邻的可移动位置
    auto moves = board.getAdjacentPositions(queen.getPosition());

    // 输出可移动的位置
    std::cout << "QueenBee adjacent positions: ";
    for (const auto& move : moves) {
        std::cout << "(" << move.x << ", " << move.y << ") ";
    }
    std::cout << std::endl;

    return 0;
}