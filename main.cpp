#include <iostream>
#include "configuration.h"
#include "player/player.h"
#include "utils/utils.h"
#include "mini/ini.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    configuration gameConfig = configuration();
//    gameConfig.parse_config("cconfig.ini");
    gameConfig.default_config();
//    mINI::INIStructure setup = hey::readIni();
//    std::cout << "hey there" << setup["configuration"]["board"] << std::endl;

    player p1(gameConfig);
    p1.setup();

    p1.displayLib();

    for (ship &s : p1.shipLibrary) {
//        utils::clearBuffer();
        std::string inputCoordinates;
        int inputDirection;
        do {
            std::cout << "Please enter the coordinates where you would like to place a " << s.type << "? " << std::endl;
            std::cin >> inputCoordinates;
            std::cout << "What direction would you like to place this? Enter 1 for horizontal or 2 for vertical. " << std::endl;
            std::cin >> inputDirection;
        } while (!(utils::validateCoordinatesFormat(inputCoordinates)) || !(utils::validateDirection(inputDirection)) || !(p1.getShipsBoard()->validatePlacement(s, inputCoordinates, inputDirection)));

        std::cout << "Valid placement: " << p1.getShipsBoard()->validatePlacement(s, inputCoordinates, inputDirection)<< std::endl;

        node n(s.type, s.length);
        std::cout << "ship type: " << s.type;
        p1.getShipsBoard()->placeNode(n, inputCoordinates, inputDirection);
        s.state = true;
        p1.displayLib();
        p1.getShipsBoard()->displayBoard();
    }

    p1.displayLib();


    node p("PATROL", 2);

//    p1.getShipsBoard()->placeNode(p, "B2");

    utils::getCoordinatesList(4, "B1", 1);

    std::cout << "Bye, World!" << std::endl;

    return 0;
}