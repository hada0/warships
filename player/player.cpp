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
    shipCount = shipLibrary.size();
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


void player::displayPlayerBoards(std::string playerName) {
    std::cout << playerName << "'s Boards" << std::endl;
    shipsBoard.displayBoard("Ships Board");
    targetBoard.displayBoard("Target Board");
    displayLib();
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
        autoplace(s);
        s.state = true;
    }
}

bool player::validateFire(std::string targetCoordinates) {
    int x = utils::parseCoordinates(targetCoordinates).at(0);
    int y = utils::parseCoordinates(targetCoordinates).at(1);
    std::string nodeStateAtCoordinates = targetBoard.getNodeStateAtCoordinates(x, y);
    return !(nodeStateAtCoordinates == "HIT" || nodeStateAtCoordinates == "MISS");
}

void player::fire(board &opponentShipBoard, std::vector<ship> &opponentShipLibrary, std::string targetCoordinates) {
    int x = utils::parseCoordinates(targetCoordinates).at(0);
    int y = utils::parseCoordinates(targetCoordinates).at(1);
    node nHit("HIT", 1);
    node nMiss("MISS", 1);
    bool hit;
    bool sunk;
    std::string nodeStateAtCoordinates = opponentShipBoard.getNodeStateAtCoordinates(x, y);
    std::cout << "OPPONENT BOARD NODE STATE: " << nodeStateAtCoordinates << std::endl;
    if (nodeStateAtCoordinates == "EMPTY") {
        targetBoard.placeNode(nMiss, targetCoordinates, 1);
        hit = 0;
        goto endOfFire;
    }
    if ((nodeStateAtCoordinates ==  "CARRIER") ||
            (nodeStateAtCoordinates == "BATTLESHIP") ||
            (nodeStateAtCoordinates == "DESTROYER") ||
            (nodeStateAtCoordinates == "SUBMARINE") ||
            (nodeStateAtCoordinates == "PATROL")) {
        for (ship &s : opponentShipLibrary) {
            for (std::string c : s.coordinates) {
                if (c == targetCoordinates) {
                    s.health--;
                    hit = 1;
                    targetBoard.placeNode(nHit, targetCoordinates, 1);
                    if (s.health == 0) {
                        s.sunk = true;
                        sunk = true;
                    }
                    goto endOfFire;
                }
            }
        }
    }
    endOfFire:
        if (hit) {
            std::cout << "Success. Target hit." << std::endl;
        } else {
            std::cout << "Oh no. Target missed." << std::endl;
        }
        if (sunk) {
            std::cout << "Woohoo. You sunk an enemy ship!" <<std::endl;
        }
}

void player::addCoordinatesListToShipLibrary(ship &s, std::string headCoordinates, int direction) {
    std::vector<std::string> coordinatesList = utils::getCoordinatesList(s.length, headCoordinates, direction);
    for (std::string c : coordinatesList) {
        s.coordinates.push_back(c);
    }
}

void player::autoplace(ship &s) {
    std::string randCoord = utils::generateRandomCoordinates(shipsBoard.getWidth(), shipsBoard.getHeight());
    int randDir = rand() % 2 + 1;
    while (!shipsBoard.validatePlacement(s, randCoord, randDir)) {
        randCoord = utils::generateRandomCoordinates(shipsBoard.getWidth(), shipsBoard.getHeight());
    }
    std::vector<std::string> listOfCoordinates = utils::getCoordinatesList(s.length, randCoord, randDir);
    for (std::string c : listOfCoordinates) {
        s.coordinates.push_back(c);
    }
    node n(s.type, s.length);
    shipsBoard.placeNode(n, randCoord, randDir);
}


