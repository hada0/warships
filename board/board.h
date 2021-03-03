//
// Created by HongAnn Dao on 02/03/2021.
//

#ifndef WARSHIPS_BOARD_H
#define WARSHIPS_BOARD_H

#include <string>

class board {
private:
    int height{};
    int width{};

public:
    board();

    void setDimensions(int height, int width);

    static bool validate(std::string dimensions);
};

#endif //WARSHIPS_BOARD_H
