#include <iostream>
#include "configuration.h"
#include "player/player.h"
#include "utils/utils.h"
#include "mini/ini.h"
#include "board/board.h"
#include "hey.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    configuration gameConfig = configuration();
//    gameConfig.parse_config("cconfig.ini");
    gameConfig.default_config();
//    mINI::INIStructure setup = hey::readIni();
//    std::cout << "hey there" << setup["configuration"]["board"] << std::endl;

    player p1(gameConfig);
    p1.setup();
//
    p1.displayLib();

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
//    auto ref = p1.getMovesBoard()->getGrid();

//    for (std::vector<node> i : *p1.getMovesBoard()->getGrid()) {
//        std::cout << "thing\n";
//    }
//
//    std::string n = p1.getMovesBoard()->getNodeStateAtCoordinates(2,2);
//    bool m = p1.getMovesBoard()->validateCoordinates("B3");
//    std::cout << "nodestate" << m << std::endl;
//
//    node *p = new node("PATROL", 2);



    node p("PATROL", 2);

    p1.getShipsBoard()->placeNode(p, "B2");
    p1.getShipsBoard()->displayBoard();

    std::cout << "Bye, World!" << std::endl;

    return 0;
}