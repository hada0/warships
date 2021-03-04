//
// Created by HongAnn Dao on 02/03/2021.
//

#include "player.h"

#include <utility>
#include "../tabulate/tabulate.h"
#include "../utils/utils.h"


void player::setup() {
    movesBoard = config.getGameBoard();
    movesBoard.createBoard();
    shipsBoard = config.getGameBoard();
    shipsBoard.createBoard();
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

bool player::placeShip(ship ship, std::string coordinatesStr) {
}

bool player::validateCoordinates(std::string coordinatesStr) {
    std::vector<int> coordinates = utils::parseCoordinates(coordinatesStr);

    return false;
}


