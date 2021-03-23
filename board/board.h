//
// Board contains attributes of the board, set from the configuration file.
//
// Each cell on a board is populated with a node. And each node is created based on the ships being handled.
//

#ifndef WARSHIPS_BOARD_H
#define WARSHIPS_BOARD_H

#include <string>
#include <map>
#include <vector>
#include "../board/board.h"

// Nodes represent the state of each cell in a grid.
// TYPES include: EMPTY, HIT, MISS, CARRIER, BATTLESHIP, DESTROYER, SUBMARINE, PATROL.
// Length is set to 1 if the type is HIT, MISS or EMPTY. Otherwise it is set to the length defined in the config file.
struct node {
    node(std::string type, int length) : type(type), length(length) {}

    std::string type = "EMPTY";
    int length = 1;
};

// Ships represent an individual ship. This stores information on the ship's type, length, health, and if the ship has
// been sunken and/or deployed.
struct ship {
    ship(const std::string &type, int length) : type(type), length(length) {}

    std::string type;
    int length;
    int health = length;
    std::vector<std::string> coordinates;
    // sunk is set to true if the ship has been sunk.
    bool sunk = 0;
    // state is set to true if it has been deployed.
    bool state = 0;
};

class board {
private:
    int height{};
    int width{};
    std::vector<std::vector<node>> grid;

public:
    board(int height, int width);

    int getHeight() const;

    int getWidth() const;

    // Creates a blank board and populates each cell with an EMPTY node.
    void createBoard();

    // Retrieve the current node state of the cell.
    std::string getNodeStateAtCoordinates(int x, int y);

    // Check placement coordinates have not been attempted before.
    bool validatePlacement(ship s, std::string coordinatesStr, int direction);

    // Print the board.
    void displayBoard(std::string title);

    // Print a readable format of the node onto the board.
    std::string printCellValue(node& n);

    // Update the state of the node with valid coordinates.
    void placeNode(node& n, std::string coordinateStr, int direction);
};

#endif //WARSHIPS_BOARD_H
