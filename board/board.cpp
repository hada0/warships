//
// Created by HongAnn Dao on 02/03/2021.
//

#include <iostream>
#include "board.h"
#include "../mini/ini.h"
#include "../utils/utils.h"

ship::ship(std::string type, int length) : type(type), length(length) {}

//bool board::validate(std::string dimensions) {
//    return dimensions.find("x") != std::string::npos;
//}

board::board() {}

void board::setDimensions(int height, int width) {
    height = height;
    width = width;
}

void board::createBoard() {
    std::vector<nodeState> columns(height);
    for (int i = 0; i < height; i++) {
        columns.push_back(nodeState::EMPTY);
    }

    std::vector<std::vector<nodeState>> rows;
    for (int i = 0; i < width; i++) {
        rows.push_back(columns);
    }

    grid = rows;
}



