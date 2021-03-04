//
// Created by HongAnn Dao on 02/03/2021.
//

#include "player.h"

#include <utility>
#include "../tabulate/tabulate.h"


void player::setup() {
    movesBoard = config.getGameBoard().createBoard();
    shipsBoard = config.getGameBoard().createBoard();
    shipLibrary = config.getShipLibrary();
}

//player(const configuration &config) : config(config) {}

void player::displayKey() {
    tabulate::Table lib;
    std::string state;
    lib.add_row({"SHIP TYPE", "STATUS"});
    for (ship s : shipLibrary) {
        if (!s.state) { state = "AVAILABLE";} else {state = "DEPLOYED";}
        lib.add_row({s.type, state});
    }
    std::cout << lib << std::endl;
}

player::player(const configuration &config) : config(config) {}
