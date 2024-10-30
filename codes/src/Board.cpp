#include "Board.h"
#include "Insect.h"
#include "Position.h"
#include "PlayerControl.h"
#include <iostream>

Board::Board() {
    grid = std::vector<std::vector<Insect*>>(size, std::vector<Insect*>(size, nullptr));
}

void Board::updateBoard() {
    // 调用window方法更新视图
}

bool Board::checkGameEnd() const {
    const PlayerControl* playerControl = PlayerControl::getInstance();
    const Player* nextPlayer = playerControl->getNextPlayer();
    QueenBee* queenBeeRival = nextPlayer->getQueenBee();
    const std::vector<Position> positions = getAdjacentPositions(queenBeeRival->getposition());
    for(int i = 0; i < positions.size(); i++) {
        if(isPositionFree(positions[i])) {
            return false;
        } else {
            continue;
        }
    }
    return true;
}

void Board::checkGrid(std::ostream& os = std::cout) const {
    for (int row = 0; row < grid.size(); ++row) {
        if (row % 2 == 0) {
            os << "  ";
        }

        for (const auto col : grid[row]) {
            if (col != nullptr) {
                // 根据昆虫的类型进行输出
                switch (insect->whichType()) {
                    case InsectType::QueenBee:
                        os << "Q ";  // 蜂后
                    break;
                    case InsectType::Ant:
                        os << "A ";  // 蚂蚁
                    break;
                    case InsectType::Beetle:
                        os << "B ";  // 甲虫
                    break;
                    case InsectType::Grasshopper:
                        os << "G ";  // 蚂蚱
                    break;
                    case InsectType::Spider:
                        os << "S ";  // 蜘蛛
                    break;
                    default:
                        os << ". ";  // 如果没有匹配到昆虫类型，打印空位
                }
            } else {
                os << ". ";  // 如果格子为空，打印 "."
            }
        }
        os << std::endl;  // 每行结束后换行
    }
}

inline std::vector<std::vector<Position>>* Board::getTotalBoard() {
    return &totalBoard;
}

// 获取指定位置的相邻位置
// 使用的时候要注意delete[]
Position* Board::getAdjacentPositions(const Position& pos) const {
    auto* adjacentPositions = new Position[6];  // 动态分配内存，最多有 6 个相邻位置
    int index = 0;

    if (pos.x + 1 <= size / 2)
        adjacentPositions[index++] = totalBoard[pos.y][pos.x + 1];

    if (pos.x - 1 >= -size / 2)
        adjacentPositions[index++] = totalBoard[pos.y][pos.x - 1];

    if (pos.y + 1 <= size / 2)
        adjacentPositions[index++] = totalBoard[pos.y + 1][pos.x];

    if (pos.y - 1 >= -size / 2)
        adjacentPositions[index++] = totalBoard[pos.y - 1][pos.x];

    if (pos.x + 1 <= size / 2 && pos.y - 1 >= -size / 2)
        adjacentPositions[index++] = totalBoard[pos.y - 1][pos.x + 1];

    if (pos.x - 1 >= -size / 2 && pos.y + 1 <= size / 2)
        adjacentPositions[index] = totalBoard[pos.y + 1][pos.x - 1];

    return adjacentPositions;  // 返回指向动态分配数组的指针
}

std::vector<Position> Board::getValidPositions(const Insect& insect) const {
    return insect.getPortee(grid, totalBoard);
};

// 检查指定位置是否为空
bool Board::isPositionFree(const Position& pos) const {
    for (const auto& row : grid) {
        for (const auto& insect : row) {
            if (insect != nullptr) {
                if (insect->getPosition().x == pos.x && insect->getPosition().y == pos.y) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Board::isValidPosition(Insect* insect, const Position& target) {
    // 此时昆虫已经被选择
    // 用户已经选择了target目标位置，传入了这个函数
    for(auto it = insect->portee.begin(); it != insect->portee.end(); ++it) {
        if(*it == target) {
            return true;
        }
    }
    return false;
}

// 在指定位置放置昆虫
void Board::placePiece(Insect* insect, const Position* pos) {
    grid[pos->y][pos->x] = insect;
    insect->setPosition(*pos);  // 设置昆虫的位置
    // 以后要加上高亮区块
    // 输出调试信息
    std::cout << "Placed insect at position (" << pos->x << ", " << pos->y << ")" << std::endl;
    updateBoard();
}

// 这是昆虫移动的入口函数，所有其他的判断都要在里边执行
void Board::moveOrNewPiece(Insect* insect, const Position* newPos) {
    // 既然可以执行这个函数，说明已经同意可以被选择，拿起后蜂巢是完整的（或者本来就是从用户的包里取用）
    // 位置是否合法已经判断过了，这里默认是合法的
    if(!insect->isInBag()) {
        // 如果从包里拿出来的，就没有旧位置
        grid[insect->getPosition().y][insect->getPosition().x] = nullptr;
    }

    placePiece(insect, newPos);
}

void highLight() {
    // 暂时不用
}

void cancelHighLight() {
    // 暂时不用
}

void isGridEntier() {
    // 待写逻辑
}