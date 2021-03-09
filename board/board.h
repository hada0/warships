//
// Created by HongAnn Dao on 02/03/2021.
//

#ifndef WARSHIPS_BOARD_H
#define WARSHIPS_BOARD_H

#include <string>
#include <map>
#include <vector>
#include "../board/board.h"

// node will represent the state of each cell in a grid.
// TYPES include: EMPTY, HIT, MISS, CARRIER, BATTLESHIP, DESTROYER, SUBMARINE, PATROL.
struct node {
    node(std::string type, int length);

    std::string type = "EMPTY";
    int length = 1;

    // state is populated if it is a boat that needs to be deployed.
    bool state = 0;
    int health = length;
};

class board {
private:
public:
    int getHeight() const;

    int getWidth() const;

private:
    int height{};
    int width{};
public:
    board(int height, int width);

private:
    std::vector<std::vector<node>> grid;
public:
    const std::vector<std::vector<node>> *getGrid() const;

    //    bool validate(std::string dimensions);

    void createBoard();

    std::string getNodeStateAtCoordinates(int x, int y);

    bool validateCoordinates(std::string coordinatesStr);

};

#endif //WARSHIPS_BOARD_H
