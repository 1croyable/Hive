//
// Created by wangj on 24-10-28.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "Insect.h"

enum class PlayerType {
    Human,
    Robot
};

class Player {

public:
    Player();
    ~Player();
    [[nodiscard]] const QueenBee* getQueenBee() const;
    [[nodiscard]] PlayerType type() const;
private:
    PlayerType playerType;
};

PlayerType Player::type() const {
    return playerType;
}

#endif //PLAYER_H
