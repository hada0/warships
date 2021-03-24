//
// Created by HongAnn Dao on 02/03/2021.
//

#ifndef WARSHIPS_PLAYER_H
#define WARSHIPS_PLAYER_H

#include <vector>
#include <regex>
#include <iostream>
#include "../board/board.h"
#include "../config/configuration.h"

class player {
private:
    std::string name;
    configuration config;
    board targetBoard = board(config.getHeight(), config.getWidth());
    board shipsBoard = board(config.getHeight(), config.getWidth());

public:
    std::vector<ship> shipLibrary;
    int remainingOpponentShips;

    player(configuration config);

    board *getShipsBoard();

    // Configures player setup based on configuration.
    void setup();

    // Prints the player's ship library to view ship statuses and health.
    void displayLib();

    // Print the up-to-date player boards.
    void displayPlayerBoards(std::string playerName);

    // Clears the players ship board for new ship placement.
    void resetShipsboard();

    // Place the given ship at random and valid coordinates.
    void autoplace(ship &s);

    // Autoplace all ships that haven't been placed at random and valid coordinates.
    void autoplaceRemaining();

    // Check the coordinates have not been attempted to fire at previously.
    bool validateFire(std::string targetCoordinates);

    // Update the ship board and ship library statuses after a fire.
    void fire(board &opponentShipBoard, std::vector<ship> &opponentShipLibrary, std::string targetCoordinates);

    // Select a random and valid coordinate to fire at.
    void autoFire(board &opponentShipBoard, std::vector<ship> &opponentShipLibrary);

    // Update the ship library with all the coordinates it is placed at.
    void addCoordinatesListToShipLibrary(ship &s, std::string headCoordinates, int direction);
};
#endif //WARSHIPS_PLAYER_H
