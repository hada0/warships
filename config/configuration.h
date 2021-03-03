//
// Created by HongAnn Dao on 02/03/2021.
//

#ifndef WARSHIPS_CONFIGURATION_H
#define WARSHIPS_CONFIGURATION_H

#include <map>
#include <vector>
#include "../board/board.h"

struct ship {
    ship(std::string type, int length, int lifePoints);

    std::string type = "";
    int length = 0;
    int lifePoints = 0;
};

class configuration {
private:
    bool mines;
    bool salvo;
    bool autoplaceAll;
    board gameBoard;
    std::vector<ship> shipLibrary;

public:
    configuration();

    void parse_config(std::string fileName);

    void default_config();

};

#endif //WARSHIPS_CONFIGURATION_H
