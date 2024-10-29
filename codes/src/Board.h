#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include "Position.h"
#include "Insect.h"  // 确保包含了 Insect.h 文件
#include "Position.h"

// ======之所以不把Board设计成单例模式，是考虑到未来可能扩展为多个棋盘在一场游戏中=====
class Board {
public:
    // 与棋盘本身有关
    Board();
    ~Board() = default;
    void updateBoard(); // 用在移动/放置昆虫后，因为昆虫本身自己的信息已经改变，由于grid使用指针，会同步进行数据改变，但是试图不一定改变，所以内部应该调用window方法改变试图
    bool checkGameEnd(); // 每次昆虫操作后都要检查一遍
    void checkGrid(std::ostream& os) const; // 格式化输出蜂巢状态
    [[nodiscard]] inline const std::vector<std::vector<Insect *>> *getGrid() const; // 返回蜂巢，用于判断是否可以获取昆虫等操作
    inline std::vector<std::vector<Position>>* getTotalBoard();
    bool isGridEntier(); // 判断蜂巢的完整性

    // 与位置、移动相关
    [[nodiscard]] Position* getAdjacentPositions(const Position& pos) const; // 获取相邻的位置
    [[nodiscard]] std::vector<Position> getValidPositions(const Insect&) const; // 被用于isValidMove判断，计算某棋盘/用户包里的昆虫可以在棋盘上走的位置
    [[nodiscard]] bool isPositionFree(const Position& pos) const; // 判断某位置是否没有被占用（不代表有效）
    // 声明为static是因为这里没有使用类的对象，通过board实现完全是语义上的用途，实际上在用户点击棋子的时候就应该在特定的被点击昆虫类中调用函数算好了可以移动的地方
    static bool isValidMove(const Insect& insect, const Position& target); // 对于昆虫在这上边是否有效，应当在内部调用昆虫自己的判定

    // 与昆虫操作相关
    void placePiece(Insect* insect, const Position& pos); // 只负责防止，不负责核对
    void moveOrNewPiece(Insect* insect, const Position& newPos); // 应当被playerControl调用，不能自己使用
    void cancelHighLight(); // 取消显示昆虫可以走的区域
    void highLight(); // 显示昆虫可以走的区域

private:
    std::vector<std::vector<Insect*>> grid; // 蜂巢
    std::vector<std::vector<Position>> totalBoard; // 完整的棋盘，仅表示区域坐标，从初始化就是定值
    int size = 21; // 区域大小
    std::vector<Position> highLighted; // 被高亮的区域
};

const std::vector<std::vector<Insect *>>* Board::getGrid() const {
    return &grid;
}

#endif // BOARD_H