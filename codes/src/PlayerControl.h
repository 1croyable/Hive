//
// Created by wangj on 24-10-28.
//
#include "Player.h"

#ifndef PLAYERCONTROL_H
#define PLAYERCONTROL_H


class PlayerControl {
public:
        inline static PlayerControl* getInstance();
        [[nodiscard]] Player& getCurrentPlayer() const; // 返回当前正在操作的玩家
        [[nodiscard]] Player& getNextPlayer() const; // 返回对手

private:
        PlayerControl();
        ~PlayerControl();

        static PlayerControl* instance;// 唯一实例
        int currentPlayerIndex;
};


PlayerControl* PlayerControl::getInstance() {
        if (instance == nullptr) {
                instance = new PlayerControl();
        }
        return instance;
}

#endif //PLAYERCONTROL_H
