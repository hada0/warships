//
// Created by HongAnn Dao on 02/03/2021.
//

#ifndef WARSHIPS_PLAYER_H
#define WARSHIPS_PLAYER_H

#include <vector>
#include <regex>
#include <iostream>
#include "../board/board.h"
#include "../configuration.h"


class player {
private:
    std::string name;
    configuration config;
    board targetBoard = board(config.getHeight(), config.getWidth());
    board shipsBoard = board(config.getHeight(), config.getWidth());
public:
    board *getTargetBoard();

    board *getShipsBoard();

public:
    player(configuration config);

    std::vector<ship> shipLibrary;

    void setup();

    void displayLib();

    void resetShipsboard();

    void autoplaceRemaining();

    bool validateFire(board &opponentShipBoard, std::string targetCoordinates);

    void fire(board &opponentShipBoard, std::string targetCoordinates);


};

#endif //WARSHIPS_PLAYER_H
