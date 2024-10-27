#include "Board.h"
#include "Insect.h"
#include "Position.h"
#include <iostream>
Board::Board() {
    // 初始化 10x10 的棋盘，每个格子都为空 (nullptr)
    grid = std::vector<std::vector<Insect*>>(10, std::vector<Insect*>(10, nullptr));
}
// 获取指定位置的相邻位置
std::vector<Position> Board::getAdjacentPositions(const Position& pos) {
    std::vector<Position> adjacentPositions;
    // 添加四个方向上的相邻位置，同时检查边界
    if (pos.x + 1 < grid.size())
        adjacentPositions.push_back(Position(pos.x + 1, pos.y));

    if (pos.x - 1 >= 0)
        adjacentPositions.push_back(Position(pos.x - 1, pos.y));

    if (pos.y + 1 < grid[0].size())
        adjacentPositions.push_back(Position(pos.x, pos.y + 1));

    if (pos.y - 1 >= 0)
        adjacentPositions.push_back(Position(pos.x, pos.y - 1));

    return adjacentPositions;
}


// 检查指定位置是否为空
bool Board::isPositionFree(const Position& pos) {
    bool isFree = grid[pos.x][pos.y] == nullptr;
    std::cout << "Checking if position (" << pos.x << ", " << pos.y << ") is free: " << (isFree ? "Yes" : "No") << std::endl;
    return isFree;
}

// 在指定位置放置昆虫
void Board::placePiece(Insect* insect, const Position& pos) {
    grid[pos.x][pos.y] = insect;
    insect->setPosition(pos);  // 设置昆虫的位置

    // 输出调试信息
    std::cout << "Placed insect at position (" << pos.x << ", " << pos.y << ")" << std::endl;
}

// 移动昆虫
void Board::movePiece(Insect* insect, const Position& newPos) {
    Position oldPos = insect->getPosition();
    grid[oldPos.x][oldPos.y] = nullptr;  // 清空旧位置
    placePiece(insect, newPos);          // 在新位置放置昆虫
}