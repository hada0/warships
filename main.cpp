#include <iostream>
#include "config/configuration.h"
#include "player/player.h"
#include "utils/utils.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    configuration gameConfig = configuration();
    gameConfig.default_config();

    player p1(gameConfig);
    p1.setup();

    p1.displayKey();

//    for (ship s : p1.shipLibrary) {
//        std::string inputCoordinates;
//        do {
//            utils::clearBuffer();
//            std::cout << "Please enter the coordinates where you would like to place a " << s.type << "? " << std::endl;
//            std::cin >> inputCoordinates;
//        } while (!utils::validateCoordinatesFormat(inputCoordinates));
//
//
//
//    }

    std::vector<int> c;
    c = utils::parseCoordinates("A2");

    std::cout << "Bye, World!" << std::endl;

    return 0;
}