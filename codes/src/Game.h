//
// Created by wangj on 2024/10/28.
//

#ifndef GAME_H
#define GAME_H
#include <Board.h>


class Game {
    enum class GameState {
        Playing,
        Paused,
        Ended
    };
    public:

    private:
        PlayerControl playerControl = PlayerControl();
        Board board = Board();
        bool ifRob = false;
        GameState gameState = Ended;
};



#endif //GAME_H
