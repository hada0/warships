//
// Created by HongAnn Dao on 02/03/2021.
//

#ifndef WARSHIPS_PLAYER_H
#define WARSHIPS_PLAYER_H

#include <vector>
#include <regex>
#include "../board/board.h"
#include "../configuration.h"


class player {
private:
    configuration config;
    board movesBoard = board(config.getHeight(), config.getWidth());
    board shipsBoard = board(config.getHeight(), config.getWidth());
public:
    board *getMovesBoard();

    board *getShipsBoard();

public:
    player(configuration config);

    std::vector<node> shipLibrary;


    void setup();

    void displayBoard();

    void displayLib();

    std::string printCellValue(node n);

//    bool placeShip(ship ship, std::string coordinates);

};

#endif //WARSHIPS_PLAYER_H
