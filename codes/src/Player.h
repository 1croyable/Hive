//
// Created by wangj on 24-10-28.
//
#include "Insect.h"

#ifndef PLAYER_H
#define PLAYER_H



class Player {
public:
    Player();
    ~Player();
    [[nodiscard]] const QueenBee* getQueenBee() const;
};



#endif //PLAYER_H
