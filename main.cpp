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
    player p2(gameConfig);
    p1.setup();
    p2.setup();

    std::string inputCoordinates;
    int inputDirection;

    regularPlace:
        for (ship &s : p1.shipLibrary) {
            do {
                std::cout << "Please enter the coordinates where you would like to place a " << s.type
                          << " ship. E.g. B3 or D2." << std::endl;
                std::cout << "To AUTOPLACE all your remaining ships, enter \"A\"." << std::endl;
                std::cout << "To RESET your board at any point, enter \"R\"." << std::endl;
                std::cout << "To QUIT the game, \"Q\"." << std::endl;
                std::cin >> inputCoordinates;
                std::cout
                        << "What direction would you like to place this? Enter 1 for horizontal or 2 for vertical. Enter 0 if you have chosen to autoplace, reset or quit your game."
                        << std::endl;
                std::cin >> inputDirection;
                if ((inputCoordinates == "a" || inputCoordinates == "A") && inputDirection == 0) {
                    goto autoplace;
                } else if (((inputCoordinates == "r" || inputCoordinates == "R") && inputDirection == 0)) {
                    std::cout << "Shipsboard reset." << std::endl;
                    p1.resetShipsboard();
                    p1.getShipsBoard()->displayBoard("Player 1 Ships");
                    goto regularPlace;
                } else if ((inputCoordinates == "q" || inputCoordinates == "Q") && inputDirection == 0) {
                    std::cout << "GAME ENDED." << std::endl;
                    return 0;
                }
                if (!utils::validateCoordinatesFormat(inputCoordinates) || !utils::validateDirection(inputDirection)) {
                    std::cout << "Invalid coordinates format. Please try again.." << std::endl;
                    continue;
                }
                if (!(p1.getShipsBoard()->validatePlacement(s, inputCoordinates, inputDirection))) {
                    std::cout << "Coordinates fall out of range or already occupied. Please try again." << std::endl;
                }
            } while (!(utils::validateCoordinatesFormat(inputCoordinates))
                     || !(utils::validateDirection(inputDirection))
                     || !(p1.getShipsBoard()->validatePlacement(s, inputCoordinates, inputDirection)));

            node n(s.type, s.length);
            p1.getShipsBoard()->placeNode(n, inputCoordinates, inputDirection);
            s.state = true;
            utils::clearConsole();
            p1.getShipsBoard()->displayBoard("Player 1 Ships");
            p1.getTargetBoard()->displayBoard("Player 1 Target");
            p1.displayLib();
        }

    autoplace:
        p1.autoplaceRemaining();
        p1.getShipsBoard()->displayBoard("Player 1 Ships");
        p1.getTargetBoard()->displayBoard("Player 1 Target");
        p1.displayLib();


    p2.autoplaceRemaining();
    p2.getShipsBoard()->displayBoard("Computer Ships");
    p2.getTargetBoard()->displayBoard("Computer Target");
    p2.displayLib();

//    ship s("PATROL", 2);


    std::cout<<utils::generateRandomCoordinates(8,8) << std::endl;


    node p("PATROL", 2);

//    p1.getShipsBoard()->placeNode(p, "B2");

    utils::getCoordinatesList(4, "B1", 1);

    std::cout << "Bye, World!" << std::endl;

    return 0;
}