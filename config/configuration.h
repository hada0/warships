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

    // Retrieve data from the configuration file and store in iniContents map.
    void parseConfig(std::string fileName);

    // Populate the class attributes from iniContents. These will be used to set up the game.
    void setupGameConfig();

    // Construct the ship library based on length and quantity retrieved from the config file.
    void addToShipLibrary(std::string type, int length, int quantity);
};

#endif //WARSHIPS_CONFIGURATION_H
