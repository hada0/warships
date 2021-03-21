//
// Created by HongAnn Dao on 02/03/2021.
//

#include "player.h"

#include <utility>
#include <variant>
#include <iostream>

#include "../tabulate/tabulate.h"
#include "../utils/utils.h"
#include "../board/board.h"

using Row_t = std::vector<std::variant<std::string, const char *, tabulate::Table>>;

void player::setup() {
    targetBoard.createBoard();
    shipsBoard.createBoard();
    shipLibrary = config.getShipLibrary();
}

void player::displayLib() {
    tabulate::Table lib;
    std::string state;
    lib.add_row({"SHIP TYPE", "STATUS", "HEALTH"});
    for (ship &s : shipLibrary) {
        std::string shipHealth = std::to_string(s.health) + "/" + std::to_string(s.length);
        if (!s.state) { state = "AVAILABLE";} else {state = "DEPLOYED";}
        lib.add_row({s.type, state, shipHealth});
    }
    std::cout << lib << std::endl;
}

player::player(configuration config) : config(std::move(config)) {}


board *player::getTargetBoard() {
    return &targetBoard;
}

board *player::getShipsBoard() {
    return &shipsBoard;
}

void player::resetShipsboard() {
    shipsBoard = board(config.getHeight(), config.getWidth());
    shipsBoard.createBoard();
}

void player::autoplaceRemaining() {
    for (ship &s : shipLibrary) {
        if (s.state) {continue;}
        getShipsBoard()->autoPlace(s);
        s.state = true;
    }
}

bool player::validateFire(board &opponentShipBoard, std::string targetCoordinates) {
    int x = utils::parseCoordinates(targetCoordinates).at(0);
    int y = utils::parseCoordinates(targetCoordinates).at(1);
    std::string nodeStateAtCoordinates = opponentShipBoard.getNodeStateAtCoordinates(x, y);
    if (nodeStateAtCoordinates == "HIT" || nodeStateAtCoordinates == "MISS") {
        std::cout << "Invalid target. Coordinates has been hit previously." << std::endl;
        return false;
    }
    return true;
}

//void player::fire(board &opponentShipBoard, std::string targetCoordinates) {
//    int x = utils::parseCoordinates(targetCoordinates).at(0);
//    int y = utils::parseCoordinates(targetCoordinates).at(1);
//    node nHit("HIT", 1);
//    node nMiss("MISS", 1);
//    std::string returnString;


//    std::string nodeStateAtCoordinates = opponentShipBoard.getNodeStateAtCoordinates(x, y);
//    if (nodeStateAtCoordinates == "EMPTY") {
//        targetBoard.placeNode(nMiss, targetCoordinates, 1);
//        std::cout << "Oh no! Target missed." << std::endl;
//    }
//    if (nodeStateAtCoordinates == "CARRIER") {
//        for (ship &s : shipLibrary) {
//            for (std::string c : s.coordinates) {
//                if (c == targetCoordinates) {
//                    s.health--;
//                    std::cout << "Success! Target hit." << std::endl;
//                    goto endOfFire;
//                }
//            }
//        }
//    }
//
//    endOfFire:
//
//}


