#include <iostream>
#include "config/configuration.h"
#include "player/player.h"
#include "utils/utils.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
////////////////////////////////////////////////////// CONFIG SETUP /////////////////////////////////////////////////////
    configuration config;
    config.parseConfig("gameConfig.ini");
    config.setupGameConfig();
    int gameMode;
    std::string inputCoordinates;
    int inputDirection;
    std::string playerConfirmation;
    std::string targetCoordinates;
    std::string victor;
    std::string endTurn;

    player p1(config);
    player p2(config);
    p1.setup();
    p2.setup();

    std::cout << "Welcome. Select a battleship mode:" << std::endl;
    std::cout << "1) Player vs. Computer" << std::endl;
    std::cout << "2) Two Player game" << std::endl;
    std::cout << "3) Quit game." << std::endl;
    std::cin >> gameMode;

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
//                    utils::clearConsole();
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
                    } else if (playerConfirmation == "N" || playerConfirmation == "n") {
                        p1.resetShipsboard();
                        goto regularPlace;
                    }
                } while (!(playerConfirmation == "Y" || playerConfirmation == "y" || playerConfirmation == "N" ||
                           playerConfirmation == "n"));

                p2.autoplaceRemaining();
                p2.displayPlayerBoards("COMPUTER");

    ////////////////////////////////////////////////////// GAME START /////////////////////////////////////////////////////
            playerTurn:
            std::cout << "*********************************** P L A Y E R  1 ***********************************" << std::endl;
            std::cout << "It's your turn. Enter coordinates to target, enter A to autofire or enter Q to quit the game."
                          << std::endl;
                std::cin >> targetCoordinates;
                targetCoordinates = utils::coordinatesToUpper(targetCoordinates);
                if (targetCoordinates == "A") {
                    p1.autoFire(*p2.getShipsBoard(), p2.shipLibrary);
                    goto endPlayerTurn;
                } else if (targetCoordinates == "Q") {
                    std::cout << "GAME QUIT." << std::endl;
                    return 0;
                }
                if (!utils::validateCoordinatesFormat(targetCoordinates)) {
                    std::cout << "Invalid coordinates format. Please try again." << std::endl;
                    goto playerTurn;
                }
                if (!p1.validateFire(targetCoordinates)) {
                    std::cout << "Invalid target. Coordinates has been hit previously." << std::endl;
                    goto playerTurn;
                }
                p1.fire(*p2.getShipsBoard(), p2.shipLibrary, targetCoordinates);
                p1.displayPlayerBoards("PLAYER 1");

            endPlayerTurn:
                if (p1.remainingOpponentShips == 0) {
                    victor = "PLAYER 1";
                    goto endGame;
                }
                std::cout << "Enter X to end your turn." << std::endl;
                std::cin >> endTurn;
                if (!(endTurn == "X" || endTurn == "x")) {
                    goto endPlayerTurn;
                }

            ComputerTurn:
                std::cout << "*********************************** C O M P U T E R ***********************************" << std::endl;
                std::cout << "It's Computer's turn." << std::endl;
                do {
                    targetCoordinates = utils::generateRandomCoordinates(p2.getShipsBoard()->getWidth(),
                                                                         p2.getShipsBoard()->getHeight());
                } while (!p2.validateFire(targetCoordinates));
                p2.fire(*p1.getShipsBoard(), p1.shipLibrary, targetCoordinates);
                p2.displayPlayerBoards("COMPUTER");

                if (p2.remainingOpponentShips == 0) {
                    victor = "COMPUTER";
                    goto endGame;
                }

            endComputerTurn:
                std::cout << "Enter X to end COMPUTER turn." << std::endl;
                std::cin >> endTurn;
                if (!(endTurn == "X" || endTurn == "x")) {
                    goto endComputerTurn;
                } else {
                    goto playerTurn;
                }

            endGame:
                std::cout << "GAME OVER." << std::endl;
                std::cout << victor << " WINS." << std::endl;
                return 0;

        case 2:
            ////////////////////////////////////////////////////// GAME SETUP /////////////////////////////////////////////////////
            std::cout << "*********************************** P L A Y E R  1 ***********************************" << std::endl;
            player1RegularPlace:
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
                            goto player1autoplace;
                        } else if ((inputCoordinates == "R" && inputDirection == 0)) {
                            std::cout << "Shipsboard reset." << std::endl;
                            p1.resetShipsboard();
                            p1.getShipsBoard()->displayBoard("Player 1 Ships");
                            goto player1RegularPlace;
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
//                    utils::clearConsole();
                    p1.displayPlayerBoards("PLAYER 1");
                }

            player1autoplace:
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
                    } else if (playerConfirmation == "N" || playerConfirmation == "n") {
                        p1.resetShipsboard();
                        goto player1RegularPlace;
                    }
                } while (!(playerConfirmation == "Y" || playerConfirmation == "y" || playerConfirmation == "N" ||
                           playerConfirmation == "n"));

            player2RegularPlace:
                std::cout << "*********************************** P L A Y E R  2 ***********************************" << std::endl;
                for (ship &s : p2.shipLibrary) {
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
                            goto player2autoplace;
                        } else if ((inputCoordinates == "R" && inputDirection == 0)) {
                            std::cout << "Shipsboard reset." << std::endl;
                            p2.resetShipsboard();
                            p2.getShipsBoard()->displayBoard("Player 1 Ships");
                            goto player1RegularPlace;
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
                        if (!(p2.getShipsBoard()->validatePlacement(s, inputCoordinates, inputDirection))) {
                            std::cout << "Coordinates fall out of range or already occupied. Please try again."
                                      << std::endl;
                        }
                    } while (!(utils::validateCoordinatesFormat(inputCoordinates))
                             || !(utils::validateDirection(inputDirection))
                             || !(p2.getShipsBoard()->validatePlacement(s, inputCoordinates, inputDirection)));

                    node n(s.type, s.length);
                    p2.addCoordinatesListToShipLibrary(s, inputCoordinates, inputDirection);
                    p2.getShipsBoard()->placeNode(n, inputCoordinates, inputDirection);
                    s.state = true;
                    utils::clearConsole();
                    p2.displayPlayerBoards("PLAYER 2");
                }

            player2autoplace:
                p2.autoplaceRemaining();
                p2.displayPlayerBoards("PLAYER 1");

                do {
                    std::cout
                            << "Are you happy to CONTINUE with your current ship placement? Enter Y for yes, N to reset board and re-place ships."
                            << std::endl;
                    std::cin >> playerConfirmation;
                    if (!(playerConfirmation == "Y" || playerConfirmation == "y" || playerConfirmation == "N" ||
                          playerConfirmation == "n")) {
                        std::cout << "Invalid option entered. Please try again." << std::endl;
                    } else if (playerConfirmation == "N" || playerConfirmation == "n") {
                        p1.resetShipsboard();
                        goto player2RegularPlace;
                    }
                } while (!(playerConfirmation == "Y" || playerConfirmation == "y" || playerConfirmation == "N" ||
                           playerConfirmation == "n"));

////////////////////////////////////////////////////// GAME START /////////////////////////////////////////////////////
            player1Turn:
                std::cout << "*********************************** P L A Y E R  1 ***********************************" << std::endl;
                std::cout << "It's Player 1's turn. Enter coordinates to target, enter A to autofire or enter Q to quit the game."
                          << std::endl;
                std::cin >> targetCoordinates;
                targetCoordinates = utils::coordinatesToUpper(targetCoordinates);
                if (targetCoordinates == "A") {
                    p1.autoFire(*p2.getShipsBoard(), p2.shipLibrary);
                    p2.displayPlayerBoards("PLAYER 1");
                    goto endPlayer1Turn;
                } else if (targetCoordinates == "Q") {
                    std::cout << "GAME QUIT." << std::endl;
                    return 0;
                }
                if (!utils::validateCoordinatesFormat(targetCoordinates)) {
                    std::cout << "Invalid coordinates format. Please try again." << std::endl;
                    goto player1Turn;
                }
                if (!p1.validateFire(targetCoordinates)) {
                    std::cout << "Invalid target. Coordinates has been hit previously." << std::endl;
                    goto player1Turn;
                }
                p1.fire(*p2.getShipsBoard(), p2.shipLibrary, targetCoordinates);
                p1.displayPlayerBoards("PLAYER 1");

            endPlayer1Turn:
                if (p1.remainingOpponentShips == 0) {
                    victor = "PLAYER 1";
                    goto end2PlayerGame;
                }
                std::cout << "Enter X to end your turn." << std::endl;
                std::cin >> endTurn;
                if (!(endTurn == "X" || endTurn == "x")) {
                    goto endPlayer1Turn;
                }

            player2Turn:
                std::cout << "*********************************** P L A Y E R  2 ***********************************" << std::endl;
                std::cout << "It's Player 2's turn. Enter coordinates to target, enter A to autofire or enter Q to quit the game."
                          << std::endl;
                std::cin >> targetCoordinates;
                targetCoordinates = utils::coordinatesToUpper(targetCoordinates);
                if (targetCoordinates == "A") {
                    p2.autoFire(*p1.getShipsBoard(), p1.shipLibrary);
                    p2.displayPlayerBoards("PLAYER 2");
                    goto endPlayer2Turn;
                } else if (targetCoordinates == "Q") {
                    std::cout << "GAME QUIT." << std::endl;
                    return 0;
                }
                if (!utils::validateCoordinatesFormat(targetCoordinates)) {
                    std::cout << "Invalid coordinates format. Please try again." << std::endl;
                    goto player2Turn;
                }
                if (!p2.validateFire(targetCoordinates)) {
                    std::cout << "Invalid target. Coordinates has been hit previously." << std::endl;
                    goto player2Turn;
                }
                p2.fire(*p1.getShipsBoard(), p1.shipLibrary, targetCoordinates);
                p2.displayPlayerBoards("PLAYER 2");

                if (p2.remainingOpponentShips == 0) {
                    victor = "PLAYER 2";
                    goto end2PlayerGame;
                }

            endPlayer2Turn:
                std::cout << "Enter X to end PLAYER 2 turn." << std::endl;
                std::cin >> endTurn;
                if (!(endTurn == "X" || endTurn == "x")) {
                    goto endPlayer2Turn;
                } else {
                    goto player1Turn;
                }

            end2PlayerGame:
                std::cout << "GAME OVER." << std::endl;
                std::cout << victor << " WINS." << std::endl;
                return 0;

        case 3:
            std::cout << "GAME QUITTED.";
            return 0;

        default:
            std::cout << "You entered an invalid option. \nQuitting Game.";
            return 0;
    }
    std::cout << "Bye, World!" << std::endl;
    return 0;
}