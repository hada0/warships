//
// Created by HongAnn Dao on 02/03/2021.
//

#ifndef WARSHIPS_PLAYER_H
#define WARSHIPS_PLAYER_H

#include <vector>
#include <regex>
#include <iostream>
#include "../board/board.h"
#include "../config/configuration.h"


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

    int remainingOpponentShips;

    void setup();

    void displayLib();

    void resetShipsboard();

    void autoplaceRemaining();

    bool validateFire(std::string targetCoordinates);

    void autoplace(ship &s);

    void fire(board &opponentShipBoard, std::vector<ship> &opponentShipLibrary, std::string targetCoordinates);

    void autoFire(board &opponentShipBoard, std::vector<ship> &opponentShipLibrary);

    void displayPlayerBoards(std::string playerName);

    void addCoordinatesListToShipLibrary(ship &s, std::string headCoordinates, int direction);
};

#endif //WARSHIPS_PLAYER_H
