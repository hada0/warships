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
    std::vector<nodeState> columns(height);
    for (int i = 0; i < width; i++) {
        std::vector<nodeState> columns;
        for (int j = 0; j < height; j++) {
            columns.push_back(nodeState::EMPTY);
        }
        grid.push_back(columns);
    }
}

nodeState board::getNodeStateAtCoordinates(int x, int y) {
    std::vector<nodeState> column;
    nodeState row;
    column = getGrid()->at(x);
    row = column.at(y);
    std::cout << "hello "<< std::endl;
    return row;
}

const std::vector<std::vector<nodeState>> *board::getGrid() const {
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
    return(getNodeStateAtCoordinates(x, y) == EMPTY);
}