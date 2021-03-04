//
// Created by HongAnn Dao on 02/03/2021.
//

#ifndef WARSHIPS_CONFIGURATION_H
#define WARSHIPS_CONFIGURATION_H

#include <map>
#include <vector>
#include "../board/board.h"

class configuration {
private:
    bool mines{};
    bool salvo{};
    bool autoplaceAll{};
    board gameBoard;
public:
    static board getGameBoard();

    std::vector<ship> & getShipLibrary();

private:
    std::vector<ship> shipLibrary;

public:
    configuration();

    void parse_config(std::string fileName);

    void default_config();

};

#endif //WARSHIPS_CONFIGURATION_H
