//
// Created by wangj on 24-10-28.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "Insect.h"
#include <string>
#include <vector>

enum class PlayerType {
    Human,
    Robot
};

enum class Difficulty {
    None,
    Easy,
    Medium,
    Master
};

class Player {

public:
    // 类相关
    explicit Player(PlayerType type); // 之后扩展的时候要加上一个枚举类，表示扩展了哪几个昆虫
    ~Player() = default;
    // getters
    [[nodiscard]] inline Insect* getChoosedInsect() const; // 返回choosedInsect
    [[nodiscard]] inline const Position* getChoosedPosition() const;
    [[nodiscard]] QueenBee* getQueenBee() const;
    inline std::string* getId();
    [[nodiscard]] inline PlayerType type() const;

    // setters
    inline void chooseInsect(Insect&); // 首先是由playerControl负责选择操作，这里的chooseInsect仅仅用来改写内部Insect数据
    inline void choosePosition(const Position&);

    // 重置选择状态


    // ======移动昆虫不需要定义在玩家里，因为操作的是昆虫、棋盘，在放置.添加前玩家已经选择好了昆虫，所以选择昆虫的任务交给玩家======
    [[nodiscard]] inline bool ifHaveInsectChoosed() const; // 返回玩家的选择是否为空，这个方法可能有点多余，但是为了可维护性，我们可以有这个方法，而且我们在放置旗子/移动棋子/操作失败之后都要清空当前选择

private:
    PlayerType playerType;
    std::string id; // id使用时间戳生成，一是免去安装uuid的过程，二是为了日后扩展“玩家游玩时间”的功能
    std::vector<Insect> insects; // 玩家拥有的昆虫列表，所有的昆虫都在这，昆虫内部状态表示在棋盘山还是在玩家手里
    Insect* choosedInsect = nullptr;
    const Position* choosedPosition = nullptr; // 位置是const，昆虫不是const，因为位置没有需要改变的变量，而昆虫的属性需要在后续被改变
};

PlayerType Player::type() const {
    return playerType;
}

Insect* Player::getChoosedInsect() const {
    return choosedInsect;
}

const Position* Player::getChoosedPosition() const {
    return choosedPosition;
}

void Player::chooseInsect(Insect& insect) {
    choosedInsect = &insect;
}

void Player::choosePosition(const Position& pos) {
    choosedPosition = &pos;
}

std::string* Player::getId() {
    return &id;
}

bool Player::ifHaveInsectChoosed() const {
    return choosedInsect == nullptr;
}

#endif //PLAYER_H
