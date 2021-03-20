//
// Created by HongAnn Dao on 02/03/2021.
//

#include "player.h"

#include <utility>
#include <variant>
#include <iostream>

#include "../tabulate/tabulate.h"
#include "../utils/utils.h"
#include "../board/board.h"

using Row_t = std::vector<std::variant<std::string, const char *, tabulate::Table>>;

void player::setup() {
    movesBoard.createBoard();
    shipsBoard.createBoard();
    shipLibrary = config.getShipLibrary();
}

void player::displayLib() {
    tabulate::Table lib;
    std::string state;
    lib.add_row({"SHIP TYPE", "STATUS"});
    for (ship s : shipLibrary) {
        if (!s.state) { state = "AVAILABLE";} else {state = "DEPLOYED";}
        lib.add_row({s.type, state});
    }
    std::cout << lib << std::endl;
}

player::player(configuration config) : config(std::move(config)) {}


board *player::getMovesBoard() {
    return &movesBoard;
}

board *player::getShipsBoard() {
    return &shipsBoard;
}

void player::resetShipsboard() {
    shipsBoard = board(config.getHeight(), config.getWidth());
    shipsBoard.createBoard();
}


