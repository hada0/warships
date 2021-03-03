//
// Created by HongAnn Dao on 02/03/2021.
//

#include <iostream>
#include "board.h"
#include "../mini/ini.h"
#include "../common/common.h"

bool board::validate(std::string dimensions) {
    return dimensions.find("x") != std::string::npos;
}

board::board() {}

void board::setDimensions(int height, int width) {
    height = height;
    width = width;
}
