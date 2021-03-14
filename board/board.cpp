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

node::node(std::string type, int length) : type(type), length(length) {}

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
    std::vector<node> row;
    row = getGrid()->at(x);
    node column = row.at(y);
    std::cout << "hello "<< std::endl;
    return column.type;
}

const std::vector<std::vector<node>> *board::getGrid() const {
    return &grid;
}

board::board(int height, int width) : height(height), width(width) {}


bool board::validateCoordinates(std::string coordinatesStr) {
    std::cout << coordinatesStr << "hi" << std::endl;
    std::vector<int> c = utils::parseCoordinates(coordinatesStr);
    std::cout << "bi" << std::endl;

    int x = c.at(0);
    int y = c.at(1);
    std::cout << "x :" << x << " y : " << y << std::endl;
    return(getNodeStateAtCoordinates(x, y) == "EMPTY");
}

int board::getHeight() const {
    return height;
}

int board::getWidth() const {
    return width;
}

void board::setGrid(const std::vector<std::vector<node>> &grid) {
    board::grid = grid;
}

void board::displayBoard() {
    tabulate::Table outputGrid;
    std::vector<std::vector<node>> myGrid = grid;
//    std::vector<node> x = getGrid()->at(0);

    outputGrid.format()
    .padding_left(1)
    .padding_right(1)
    .column_separator("|");

    std::ostringstream stringStream;
    std::ostringstream headers;
    headers << "_ ";
    int numOfColumns = getWidth();

    for (int column = 0; column < numOfColumns; column++) {
        int count = 0;
        if (count == (numOfColumns - 1)) {
            headers << headerAlphas.at(column);
        } else {
            headers << headerAlphas.at(column) << " ";
        }
    }

    for (int i = 0; i < myGrid.size(); i++) {
        int count = 0;
        std::vector<std::string> row;
        for (int j = 0; j < myGrid.at(i).size(); j++) {
//            std::cout << printCellValue(mx.at(j)) << std::endl;
            if (count == 0) {
                stringStream << i + 1 << " ";
            }
            if (count == (numOfColumns - 1)) {
                stringStream << printCellValue(myGrid.at(i).at(j));
            } else {
                stringStream << printCellValue(myGrid.at(i).at(j)) << " ";
                count++;
            }
        }
        stringStream << "\n";
    }
    outputGrid.add_row({headers.str()});
    outputGrid.add_row({stringStream.str()});
    std::cout << outputGrid.str() << std::endl;
}

std::string board::printCellValue(node& n) {
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

void board::placeNode(node& n, std::string coordinatesStr) {
    std::vector<int> c = utils::parseCoordinates(coordinatesStr);
    int x = c.at(0);
    int y = c.at(1);
//    std::cout << "(X, Y): " << x << "," << y << std::endl;
    grid.at(y).at(x) = n;
}
