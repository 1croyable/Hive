//
// Created by wangj on 24-10-30.
//

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player {
public:
    // 构造函数和析构函数
    HumanPlayer() : Player(PlayerType::Human) {} // 调用基类的构造函数，类型是Human
    ~HumanPlayer() = default;
};

#endif // HUMANPLAYER_H
