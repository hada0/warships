//
// Created by HongAnn Dao on 02/03/2021.
//

#include "../board/board.h"
#include <variant>
#include "../tabulate/tabulate.h"
#include <utility>
#include "../player/player.h"
#include <iostream>
#include "board.h"
#include "../mini/ini.h"
#include "../utils/utils.h"

void board::createBoard() {
    for (int i = 0; i < height; i++) {
        std::vector<node> rows;
        for (int j = 0; j < width; j++) {
            rows.push_back(node("EMPTY", 1));
        }
        grid.push_back(rows);
    }
}

std::string board::getNodeStateAtCoordinates(int x, int y) {
    return grid.at(y).at(x).type;
}

const std::vector<std::vector<node>> *board::getGrid() const {
    return &grid;
}

board::board(int height, int width) : height(height), width(width) {}

int board::getHeight() const {
    return height;
}

int board::getWidth() const {
    return width;
}

void board::setGrid(const std::vector<std::vector<node>> &grid) {
    board::grid = grid;
}

void board::displayBoard(std::string title) {
    tabulate::Table shipsGrid;
    std::vector<std::vector<node>> myShipGrid = grid;

    shipsGrid.format()
    .padding_left(1)
    .padding_right(1)
    .column_separator("|");

    std::ostringstream stringStream;
    std::ostringstream headers;
    headers << "_  ";
    int numOfColumns = getWidth();

    for (int column = 0; column < numOfColumns; column++) {
        int count = 0;
        if (count == (numOfColumns - 1)) {
            headers << headerAlphas.at(column);
        } else {
            headers << headerAlphas.at(column) << " ";
        }
    }

    for (int i = 0; i < myShipGrid.size(); i++) {
        int count = 0;
        std::vector<std::string> row;
        for (int j = 0; j < myShipGrid.at(i).size(); j++) {
            if (count == 0) {
                stringStream << i + 1;
                if (i < 9) {
                    stringStream << "  ";
                } else {
                    stringStream << " ";
                }
            }
            if (count == (numOfColumns - 1)) {
                stringStream << printCellValue(myShipGrid.at(i).at(j));
            } else {
                stringStream << printCellValue(myShipGrid.at(i).at(j)) << " ";
                count++;
            }
        }
        stringStream << "\n";
    }
    shipsGrid.add_row({title});
    shipsGrid.add_row({headers.str()});
    shipsGrid.add_row({stringStream.str()});
    std::cout << shipsGrid.str() << std::endl;
}

std::string board::printCellValue(node& n) {
    if (n.type == "EMPTY") {
        return "x";
    } else if (n.type == "HIT") {
        return "H";
    } else if (n.type == "MISS") {
        return "M";
    } else if (n.type == "CARRIER") {
        return "C";
    } else if (n.type == "BATTLESHIP") {
        return "B";
    } else if (n.type == "DESTROYER") {
        return "D";
    } else if (n.type == "SUBMARINE") {
        return "S";
    } else if (n.type == "PATROL") {
        return "P";
    }
    return "!";
}


bool board::validatePlacement(ship s, std::string coordinatesStr, int direction) {
    std::vector<std::string> coordinatesList = utils::getCoordinatesList(s.length, coordinatesStr, direction);
    for (int i = 0; i < coordinatesList.size(); i++) {
        int currentX = utils::parseCoordinates(coordinatesList.at(i)).at(0);
        int currentY = utils::parseCoordinates(coordinatesList.at(i)).at(1);
        if (currentX >= width || currentX < 0 || currentY >= height || currentY < 0) {
            return false;
        }
        if (!(getNodeStateAtCoordinates(currentX, currentY) == "EMPTY")) {
            return false;
        }
    }
    return true;
}

void board::placeNode(node& n, std::string coordinatesStr, int direction) {
    ship s(n.type, n.length);
    std::vector<std::string> coordinatesList = utils::getCoordinatesList(s.length, coordinatesStr, direction);
    for (std::string coord : coordinatesList) {
        std::vector<int> c = utils::parseCoordinates(coord);
        int x = c.at(0);
        int y = c.at(1);
        grid.at(y).at(x) = n;
    }
}

