//
// Created by HongAnn Dao on 02/03/2021.
//

#ifndef WARSHIPS_BOARD_H
#define WARSHIPS_BOARD_H

#include <string>
#include <map>
#include <vector>
#include "../board/board.h"

struct node {
    ship(std::string type, int length);

    std::string type = "hit";
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
public:
    board(int height, int width);

private:
    std::vector<std::vector<nodeState>> grid;
public:
    const std::vector<std::vector<nodeState>> *getGrid() const;

    //    bool validate(std::string dimensions);

    void createBoard();

    nodeState getNodeStateAtCoordinates(int x, int y);

    bool validateCoordinates(std::string coordinatesStr);

};

#endif //WARSHIPS_BOARD_H
