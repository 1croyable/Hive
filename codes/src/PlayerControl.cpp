//
// Created by wangj on 24-10-28.
//

#include "PlayerControl.h"

#include <Board.h>

#include "Player.h"

Player* PlayerControl::getCurrentPlayer() const {
    return players[currentPlayerIndex];
}

Player* PlayerControl::getNextPlayer() const {
    const int i = (currentPlayerIndex + 1) % 2;
    return players[i];
}

// player是事先创建好的，可以保存在堆里，现在只是添加进去
void PlayerControl::addPlayer(Player* playerPtr) {
    if(isPCPrepared()) return;
    players.push_back(playerPtr);
}

void PlayerControl::switchPlayer() {
    if(!isPCPrepared()) return;
    currentPlayerIndex = (currentPlayerIndex + 1) % 2;
}

bool PlayerControl::isCurrentPlayerHuman() const {
    const Player* currentPlayerPtr = getCurrentPlayer();
    const PlayerType playerType = currentPlayerPtr->type();
    return playerType == PlayerType::Human;
}

void PlayerControl::dropPlayer(const int index) {
    players.erase(players.begin() + index);
}

void PlayerControl::addPiece(Board* board, Insect* insect, const Position &position) const {
    if(!isPCPrepared()) return;
    // 选择包里的昆虫 -> 获取昆虫portee -> 选择位置 -> 判断新位置是否合法 -> 添加棋子
    board->moveOrNewPiece(insect, position);
    // 还要加上错误处理和高亮处理
}

void PlayerControl::makeMove(Board* board, Insect* insect, const Position &position) const {
    if(!isPCPrepared()) return;
    // 选择棋盘上的昆虫 -> 判断是否能够被选择 -> 获取昆虫portee -> 选择位置 ->  判断新位置是否合法 -> 如果合法就移动
    board->moveOrNewPiece(insect, position);
    // 还要加上错误处理和高亮处理
}

// 这里其实也想到，可以将选择的昆虫放在PlayerColtrol类中，但是未来可以扩展本队不同玩家选择的昆虫做出不同操作，比如高亮的颜色不同，我们在Player类里写也可以
void PlayerControl::chooseInsect(const Board* boardPtr, const Insect &insect) const {
    if(!isPCPrepared()) return;
    // 昆虫在包里和在棋盘里的情况是不一样的
    const Player* currentPlayerPtr = getCurrentPlayer();
    if(insect.isInBag()) {
        std::vector<Position> validPositions = boardPtr->getValidPositions(insect);

        // 这里处理高亮

        currentPlayerPtr->choosedInsect = insect;
    } else {
        // 从棋盘上选择，先判断是否能够被拿起来，判断成功执行对应的拿起来的视图操作
        if(insect.ifCanBeChoosed(boardPtr -> getGrid())) {
            // 这里先用window类执行视图操作，棋子被拿起

            std::vector<Position> validPositions = boardPtr->getValidPositions(insect);

            // 这里处理高亮

            currentPlayerPtr->choosedInsect = insect;
        } else {
            // 这里报个警告
            return;
        }
    }
}

// 更改用户选择的位置数据，然后判断用户的选择是否是有效位置
void PlayerControl::chooseTargetPos(const Position &pos) const {
    if(Board::isValidMove(getCurrentPlayer() -> choosedInsect, pos)) {
        getCurrentPlayer() -> choosedPosition = pos;
    }
}
