//
// Created by HongAnn Dao on 02/03/2021.
//

#ifndef WARSHIPS_CONFIGURATION_H
#define WARSHIPS_CONFIGURATION_H

#include <tclDecls.h>
#include <map>
#include "board.h"

struct ship {
    std::string type;
    int length;
    int lifePoints;
};

class configuration {
private:
    static bool mines;
    static bool salvo;
    static bool autoplaceAll;
    static board board;
    std::map<ship, int>;

public:
    static void parse_config(std::string fileName);



};

#endif //WARSHIPS_CONFIGURATION_H
