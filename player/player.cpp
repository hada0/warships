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

void player::displayBoard() {
    tabulate::Table grid;
    std::vector<std::vector<node>> x = *getMovesBoard()->getGrid();
    std::vector<node> y = getMovesBoard()->getGrid()->at(0);
    grid.format()
    .padding_left(1)
    .padding_right(1)
    .column_separator("|");

    std::ostringstream stringStream;

    for (std::vector<node> y : x) {
        int count = 0;
        std::vector<std::string> row;
        for (node n : y) {
            if (count == (getMovesBoard()->getWidth() - 1)) {
                stringStream << printCellValue(n);
            } else {
                stringStream << printCellValue(n) << " ";
                count++;
            }
        }
        stringStream << "\n";
    }

    grid.add_row({stringStream.str()});
    std::cout << grid.str();
}

std::string player::printCellValue(node n) {
    if (n.type == "EMPTY") {
        return "x";
    } else if (n.type == "HIT") {
        return "O";
    } else if (n.type == "MISS") {
        return "X";
    } else if (n.type == "CARRIER") {
        return "C";
    } else if (n.type == "DESTROYER") {
        return "D";
    } else if (n.type == "SUBMARINE") {
        return "S";
    } else if (n.type == "PATROL") {
        return "P";
    }
    return "!";
}


