//
// Created by HongAnn Dao on 02/03/2021.
//

#ifndef WARSHIPS_BOARD_H
#define WARSHIPS_BOARD_H

#include <string>

class board {
private:
    int height;
    int width;

public:
    board(int boardHeight, int boardWidth) : height(boardHeight), width(boardWidth) {}

//    static board* inst_;
//
//    static board *getInstance(const int width, const int height);
//
//    static board configure(const std::string);
//
    static bool validate(std::string dimensions);
};

#endif //WARSHIPS_BOARD_H
