//
// Created by wangj on 24-10-28.
//

#include "Player.h"
#include <chrono>

Player::Player(PlayerType type):playerType(type) {
    // 获取当前时间点
    const auto now = std::chrono::system_clock::now();

    // 转换为以秒为单位的时间戳
    const auto timestamp = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();

    id = std::to_string(timestamp);
}
