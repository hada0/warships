//
// Created by HongAnn Dao on 02/03/2021.
//

#include "../tabulate/tabulate.h"
#include <utility>
#include "../player/player.h"
#include <iostream>
#include "board.h"
#include "../mini/ini.h"
#include "../utils/utils.h"

node::node(std::string type, int length) : type(type), length(length) {}

void board::createBoard() {
    std::vector<node> columns;
    for (int i = 0; i < width; i++) {
        std::vector<node> columns;
        for (int j = 0; j < height; j++) {
            columns.push_back(node("EMPTY", 1));
        }
        grid.push_back(columns);
    }
}

std::string board::getNodeStateAtCoordinates(int x, int y) {
    std::vector<node> column;
    column = getGrid()->at(x);
    node row = column.at(y);
    std::cout << "hello "<< std::endl;
    return row.type;
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