//
// Created by HongAnn Dao on 02/03/2021.
//

#include "player.h"

#include <utility>

void player::setup() {
    movesBoard = config.getGameBoard().createBoard();
    shipsBoard = config.getGameBoard().createBoard();
    shipLibrary = config.getShipLibrary();
}

player::player(const configuration &config) : config(config) {}

void player::displayKey() {

}


