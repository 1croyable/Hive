//
// Created by wangj on 2024/10/28.
//

#ifndef GAME_H
#define GAME_H

#include <Board.h>
#include "PlayerControl.h"

class Game {
    // 游戏状态枚举
    enum class GameState {
        Playing,
        Paused,
        Ended,
        Loading
    };

public:
    // 单例模式必须
    static Game* HIVE(); // 首次调用可以需要传入参数是否是机器人对战的HIVE游戏，再次调用可以不指定
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    // 玩家的操作
    void chooseDifficulty(const Difficulty difficulty); //用户要先选择难度
    void init(); // 此时已经选择过了 玩家 VS AI 还是 玩家1VS玩家2 玩家点击进入游戏，调用init初始化游戏玩家、棋盘
    // 游戏判断
    inline bool isGameOver() const; // 调用board的checkGameEnd函数，判断对手的蜂后有没有被围住，在每次“移动”操作后执行
private:
    // 构造函数
    Game() = default;
    ~Game() = default;

    // 单例实例
    static Game* instance;

    // 游戏属性
    bool ifThereIsARob = false; // 标记是否是和机器人对战，可用于前端显示
    Difficulty diff = Difficulty::None; // 机器人难度，默认是未选择的None
    GameState gameState = GameState::Ended;
    // 之后扩展的时候要加上一个枚举类，表示扩展了哪几个昆虫，在init函数里要一起初始化

    // 玩家控制相关属性
    PlayerControl* playerControl;

    // 棋盘控制相关属性
    std::vector<Board> boards; // 考虑到未来扩展可以有多个棋盘同时存在，我们board没有设计成单例模式而是棋盘实例，由game管理
    static constexpr short maxBoards = 1;
};

bool Game::isGameOver() const {
    for(const auto& board : boards) {
        if(board.checkGameEnd()) {
            return true;
        }
    }
    return false;
}

#endif //GAME_H
