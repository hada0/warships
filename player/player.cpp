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
    for (node s : shipLibrary) {
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

//bool player::placeShip(node& ship, std::string coordinatesStr) {
//    if (!utils::validateCoordinatesFormat(coordinatesStr)) {
//        std::cout << "Invalid coordinates format." << std::endl;
//        return false;
//    }
//    if (shipsBoard.validateCoordinates(coordinatesStr)) {
//
//        std::vector<int> c = utils::parseCoordinates(coordinatesStr);
//        int x = c.at(0);
//        int y = c.at(1);
//        std::vector<std::vector<node>> grid = *shipsBoard.getGrid();
//        std::vector<node> &yPos = grid.at(y);
//        std::cout << "before: " << yPos.at(x).type << std::endl;
//        yPos.at(x) = ship;
//        std::vector<std::vector<node>> grid2 = *shipsBoard.getGrid();
//        std::vector<node> &yPos2 = grid.at(y);
//
//        std::cout << "after: " << yPos2.at(x).type << std::endl;
////        std::cout << "after cell value: " << printCellValue(yPos2.at(x)) << std::endl;
//        std::cout << "hey dude" << std::endl;
////        shipsBoard.setGrid(grid2);
////        displayBoard();
//        return true;
//    }
//    return false;
//}


