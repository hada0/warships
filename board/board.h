//
// Created by HongAnn Dao on 02/03/2021.
//

#ifndef WARSHIPS_BOARD_H
#define WARSHIPS_BOARD_H

#include <string>
#include <map>
#include <vector>
#include "../board/board.h"

struct ship {
    ship(std::string type, int length);

    std::string type = "";
    int length = 0;
    bool state = 0;
};

enum nodeState {
    EMPTY,
    HIT,
    MISS,
    SUNK,

    CARRIER,
    BATTLESHIP,
    DESTROYER,
    SUBMARINE,
    PATROL
};

class board {
private:
    int height{};
    int width{};
    std::vector<std::vector<nodeState>> grid;

public:
    board();

    void setDimensions(int height, int width);

//    bool validate(std::string dimensions);

    void createBoard();
};

#endif //WARSHIPS_BOARD_H
