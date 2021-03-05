#include <iostream>
#include "config/configuration.h"
#include "player/player.h"
#include "utils/utils.h"
#include "board/board.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    configuration gameConfig = configuration();
    gameConfig.default_config();

    player p1(gameConfig);
    p1.setup();

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

    for (std::vector<nodeState> i : *p1.getMovesBoard()->getGrid()) {
        std::cout << "thing\n";
    }

    nodeState n = p1.getMovesBoard()->getNodeStateAtCoordinates(2,2);
    bool m = p1.getMovesBoard()->validateCoordinates("A1");
    std::cout << "nodestate" << m << std::endl;

    std::cout << "Bye, World!" << std::endl;

    return 0;
}