//
// Created by HongAnn Dao on 02/03/2021.
//

#ifndef WARSHIPS_PLAYER_H
#define WARSHIPS_PLAYER_H

#include <vector>
#include <regex>
#include "../board/board.h"
#include "../config/configuration.h"


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

    std::vector<ship> shipLibrary;


    void setup();

//    void displayBoard();

    void displayKey();

//    bool placeShip(ship ship, std::string coordinates);

};

#endif //WARSHIPS_PLAYER_H
