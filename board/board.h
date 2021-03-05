//
// Created by HongAnn Dao on 02/03/2021.
//

#ifndef WARSHIPS_BOARD_H
#define WARSHIPS_BOARD_H

#include <string>
#include <map>
#include <vector>
#include "../board/board.h"

// Node will represent the state of each cell in a grid.
struct Node {
    Node(std::string type, int length);

    std::string type = "EMPTY";
    int length = 1;

    // state is populated if it is a boat that needs to be deployed.
    bool state = 0;
    int health = length;
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
