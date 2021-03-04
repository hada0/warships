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
    std::vector<std::vector<nodeState>> movesBoard;
    std::vector<std::vector<nodeState>> shipsBoard;

private:
    configuration config;
public:
    std::vector<ship> shipLibrary;

    player(const configuration &config);

    void setup();

    void displayBoard();

    void displayKey();

    bool placeShip(ship ship, std::string coordinates);

    bool validateCoordinates(std::string coordinatesStr);

};

#endif //WARSHIPS_PLAYER_H
