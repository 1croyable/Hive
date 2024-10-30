//
// Created by wangj on 2024/10/28.
//

#include "Game.h"
#include "HumanPlayer.h"
#include "RobotPlayer.h"

// 初始化静态成员
Game *Game::instance = nullptr;

Game *Game::HIVE() {
    if (instance == nullptr) {
        instance = new Game();
    }
    return instance;
}

void Game::init() {
    // 用户已经实现选择好难度，如果用户不选择，默认难度是None，就是玩家 VS 玩家
    // 初始化玩家(同时在Player类中初始化玩家的昆虫) -> 初始化棋盘 -> 发信息给前端让前端渲染游戏界面
    playerControl = PlayerControl::getInstance();
    gameState = GameState::Loading; // 在这里可以加上前端的渲染（正在初始化游戏。。。）
    // 初始化玩家
    switch (Difficulty::None ? 2 : 1) {
        case 1:
            playerControl->addPlayer(new HumanPlayer());
            playerControl->addPlayer(new RobotPlayer(diff));
            break;
        case 2:
            playerControl->addPlayer(new HumanPlayer());
            playerControl->addPlayer(new HumanPlayer());
            break;
        default:
            // 报个错
            return;
    }
    // 初始化棋盘
    do {
        boards.push_back(Board());
    } while (boards.size() < maxBoards);

    gameState = GameState::Playing;
}

void Game::chooseDifficulty(const Difficulty difficulty) {
    diff = difficulty;
}
