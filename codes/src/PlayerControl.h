//
// Created by wangj on 24-10-28.
//

#ifndef PLAYERCONTROL_H
#define PLAYERCONTROL_H

#include "Player.h"

class PlayerControl {
public:
        // 控制器状态，避免没有添加玩家就调用实例，因为我们的单例创建的时候没有传入参数
        [[nodiscard]]  inline bool isPCPrepared() const;
        // 单例模式需要
        inline static PlayerControl* getInstance();
        PlayerControl(const PlayerControl&) = delete;
        PlayerControl& operator= (const PlayerControl&) = delete;
        // 玩家管理，玩家信息显示
        [[nodiscard]] Player* getCurrentPlayer() const; // 返回当前正在操作的玩家，用于进一步获取玩家信息
        [[nodiscard]] Player* getNextPlayer() const; // 返回对手，用于进一步获取玩家信息
        void addPlayer(Player* playerPtr); // 添加一个玩家到players
        void switchPlayer(); //切换currentPlayerIndex
        [[nodiscard]] bool isCurrentPlayerHuman() const; // 查看当前下棋的玩家是不是人类
        void dropPlayer(int index); // 扔掉指定index的玩家

        // 玩家操作，指的是游戏开始后玩家的游戏操作而不是现实中的人的操作，board由Game单例传入
        void addPiece(Board* board) const; // 添加一个旗子到棋盘上
        void makeMove(Board* board, Insect* insect, const Position& position) const; // 玩家移动棋子的入口函数
        void chooseInsect(const Board* board, Insect& insect) const; // 玩家点击了昆虫（无论是昆虫包里的还是棋盘上的）
        void chooseTargetPos(const Position& pos) const; // 玩家点击了目标位置（不论是否有空，点击了棋盘就会触发）
private:
        // 玩家实例已经提前被创建好了，现在只需要传入去初始化玩家控制器
        PlayerControl() = default;
        ~PlayerControl(); // 玩家是在game类中new出来的，所以要在这里析构;

        static PlayerControl* instance;// 唯一实例
        static constexpr int maxPlayers = 2;
        std::vector<Player*> players;  // 保存玩家
        int currentPlayerIndex = 0;
};

PlayerControl* PlayerControl::getInstance() {
        if (instance == nullptr) {
                instance = new PlayerControl();
        }
        return instance;
}

bool PlayerControl::isPCPrepared() const {
        return players.size() == maxPlayers;
}

#endif //PLAYERCONTROL_H
