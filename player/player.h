//
// Created by HongAnn Dao on 02/03/2021.
//

#ifndef WARSHIPS_PLAYER_H
#define WARSHIPS_PLAYER_H

#include <vector>
#include "../board/board.h"
#include "../config/configuration.h"

class player {
private:
    std::vector<std::vector<nodeState>> movesBoard;
    std::vector<std::vector<nodeState>> shipsBoard;

private:
    std::vector<ship> shipLibrary;
    configuration config;

public:

    player(const configuration &config);

    void setup();

    void displayBoard();

    void displayKey();

    void placeShip();



#endif //WARSHIPS_PLAYER_H
