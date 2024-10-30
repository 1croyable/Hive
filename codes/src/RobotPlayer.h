//
// Created by wangj on 24-10-30.
//

#ifndef ROBOTPLAYER_H
#define ROBOTPLAYER_H

#include "Player.h"
#include "Board.h"

class RobotPlayer : public Player {
public:
    // 构造函数
    explicit RobotPlayer(const Difficulty diff) : Player(PlayerType::Robot), difficulty(diff) {}
    ~RobotPlayer() = default;

    // RobotPlayer 特定函数
    void calculateNextMove(const Board& board) const;

private:
    Difficulty difficulty; // 机器人难度
};

#endif // ROBOTPLAYER_H
