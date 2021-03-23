#include <iostream>
#include "config/configuration.h"
#include "player/player.h"
#include "utils/utils.h"
#include "mini/ini.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

//    configuration gameConfig = configuration();
//    gameConfig.parse_config("gameConfig.ini");
//    gameConfig.defaultConfig();
//    mINI::INIStructure setup = hey::readIni();
    std::cout << "hey there" << std::endl;

    configuration config;
    std::cout << "hey there" << std::endl;

    config.parseConfig("gameConfig.ini");
    config.setupGameConfig();
    int gameMode;
    std::cout << "Welcome. Select a battleship mode:" << std::endl;
    std::cout << "1) Player vs. Computer" << std::endl;
    std::cout << "2) Quit game." << std::endl;

    std::cin >> gameMode;

    player p1(config);
    player p2(config);
    p1.setup();
    p2.setup();

    std::string inputCoordinates;
    int inputDirection;
    std::string playerConfirmation;
    std::string targetCoordinates;
    std::string victor;
    std::string endTurn;

    switch(gameMode) {
        case 1:
////////////////////////////////////////////////////// GAME SETUP /////////////////////////////////////////////////////
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
                        inputCoordinates = utils::coordinatesToUpper(inputCoordinates);
                        if (inputCoordinates == "A" && inputDirection == 0) {
                            goto autoplace;
                        } else if ((inputCoordinates == "R" && inputDirection == 0)) {
                            std::cout << "Shipsboard reset." << std::endl;
                            p1.resetShipsboard();
                            p1.getShipsBoard()->displayBoard("Player 1 Ships");
                            goto regularPlace;
                        } else if (inputCoordinates == "Q" && inputDirection == 0) {
                            std::cout << "GAME QUIT." << std::endl;
                            return 0;
                        }
                        if (!utils::validateCoordinatesFormat(inputCoordinates)) {
                            std::cout << "Invalid coordinates format. Please try again." << std::endl;
                            continue;
                        }
                        if (!utils::validateDirection(inputDirection)) {
                            std::cout << "Invalid direction. Please try again." << std::endl;
                            continue;
                        }
                        if (!(p1.getShipsBoard()->validatePlacement(s, inputCoordinates, inputDirection))) {
                            std::cout << "Coordinates fall out of range or already occupied. Please try again."
                                      << std::endl;
                        }
                    } while (!(utils::validateCoordinatesFormat(inputCoordinates))
                             || !(utils::validateDirection(inputDirection))
                             || !(p1.getShipsBoard()->validatePlacement(s, inputCoordinates, inputDirection)));

                    node n(s.type, s.length);
                    p1.addCoordinatesListToShipLibrary(s, inputCoordinates, inputDirection);
                    p1.getShipsBoard()->placeNode(n, inputCoordinates, inputDirection);
                    s.state = true;
                    utils::clearConsole();
                    p1.displayPlayerBoards("PLAYER 1");
                }

            autoplace:
                p1.autoplaceRemaining();
                p1.displayPlayerBoards("PLAYER 1");

                do {
                    std::cout
                            << "Are you happy to CONTINUE with your current ship placement? Enter Y for yes, N to reset board and re-place ships."
                            << std::endl;
                    std::cin >> playerConfirmation;
                    if (!(playerConfirmation == "Y" || playerConfirmation == "y" || playerConfirmation == "N" ||
                          playerConfirmation == "n")) {
                        std::cout << "Invalid option entered. Please try again." << std::endl;
                    }
                    if (playerConfirmation == "N" || playerConfirmation == "n") {
                        p1.resetShipsboard();
                        goto regularPlace;
                    }
                } while (!(playerConfirmation == "Y" || playerConfirmation == "y" || playerConfirmation == "N" ||
                           playerConfirmation == "n"));

                p2.autoplaceRemaining();
                p2.displayPlayerBoards("COMPUTER");

    ////////////////////////////////////////////////////// GAME START /////////////////////////////////////////////////////
            playerOneTurn:
                std::cout << "It's your turn. Enter coordinates to target, enter A to autofire or enter Q to quit the game."
                          << std::endl;
                std::cin >> targetCoordinates;
                targetCoordinates = utils::coordinatesToUpper(targetCoordinates);
                if (targetCoordinates == "A") {
                    p1.autoFire(*p2.getShipsBoard(), p2.shipLibrary);
                    goto endPlayer1Turn;
                } else if (targetCoordinates == "Q") {
                    std::cout << "GAME QUIT." << std::endl;
                    return 0;
                }
                if (!utils::validateCoordinatesFormat(targetCoordinates)) {
                    std::cout << "Invalid coordinates format. Please try again." << std::endl;
                    goto endPlayer1Turn;
                }
                if (!p1.validateFire(targetCoordinates)) {
                    std::cout << "Invalid target. Coordinates has been hit previously." << std::endl;
                    goto playerOneTurn;
                }
                p1.fire(*p2.getShipsBoard(), p2.shipLibrary, targetCoordinates);
                p1.displayPlayerBoards("PLAYER 1");

            endPlayer1Turn:
                if (p1.remainingOpponentShips == 0) {
                    victor = "PLAYER 1";
                    goto endGame;
                }
                std::cout << "Enter X to end your turn." << std::endl;
                std::cin >> endTurn;
                if (!(endTurn == "X" || endTurn == "x")) {
                    goto endPlayer1Turn;
                }

            ComputerTurn:
                std::cout << "It's Computer's turn." << std::endl;
                do {
                    targetCoordinates = utils::generateRandomCoordinates(p2.getShipsBoard()->getWidth(),
                                                                         p2.getShipsBoard()->getHeight());
                } while (!p2.validateFire(targetCoordinates));
                p2.fire(*p1.getShipsBoard(), p1.shipLibrary, targetCoordinates);
                p2.displayPlayerBoards("COMPUTER");

                if (p2.remainingOpponentShips == 0) {
                    victor = "COMPUTER";
                } else {
                    goto playerOneTurn;
                }

            endGame:
                std::cout << "GAME OVER." << std::endl;
                std::cout << victor << " WINS." << std::endl;
        case 2:
            std::cout << "GAME QUITTED.";
            return 0;
    }

    std::cout << "Bye, World!" << std::endl;
    return 0;
}