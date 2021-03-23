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
    std::map<std::string, std::string> iniContents;
    int height{};
    int width{};
    int carrierLength;
    int carrierQuantity;
    int battleshipLength;
    int battleshipQuantity;
    int destroyerLength;
    int destroyerQuantity;
    int submarineLength;
    int submarineQuantity;
    int patrolLength;
    int patrolQuantity;

    std::vector<ship> shipLibrary;

public:
    configuration();
    int getHeight() const;
    int getWidth() const;
    std::vector<ship> & getShipLibrary();
    void parseConfig(std::string fileName);
    void setupGameConfig();
    void defaultConfig();
    void addToShipLibrary(std::string type, int length, int quantity);
};

#endif //WARSHIPS_CONFIGURATION_H
