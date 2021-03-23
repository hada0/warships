//
// Created by HongAnn Dao on 02/03/2021.
//

#include <string>
#include <iostream>
#include <regex>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <random>
#include "utils.h"

void utils::clearBuffer() {
    std::cin.clear();
    // Clears the std::cin state to ensure future IO ops work correctly
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    // Clears the cin buffer including new lines or additional characters
}

void utils::clearConsole() {
    std::cout << "\x1B[2J\x1B[H";
}

std::string utils::coordinatesToUpper(std::string coordinatesStr) {
    std::string str;
    for( char& c : coordinatesStr ) str.push_back(std::toupper(c));
    return str;
}

bool utils::validateCoordinatesFormat(std::string coordinatesStr) {
    return std::regex_match(coordinatesStr, coordinates);
}

int utils::convertAlphaToInt(std::string alpha) {
    int value = 0;
    std::string str;
    auto it = std::find(headerAlphas.begin(), headerAlphas.end(), alpha);
    if (it != headerAlphas.end()) {
        value = it - headerAlphas.begin();
    }
    std::cout << "VALUE : " << value << std::endl;
    return value;
}

std::vector<int> utils::parseCoordinates(std::string str) {
    std::string tmp;
    std::vector<int> items;
    int x = 0, y = 0;
    std::smatch match;
    if (std::regex_search(str, match, coordinates)) {
        std::cout << "X1:" << x << std::endl;
        x = convertAlphaToInt(match.str(1));
        y = std::stoi(match.str(2)) - 1;
    }
    items.push_back(x);
    std::cout << "X2:" << x << std::endl;
    items.push_back(y);
    return items;
}

std::vector<int> utils::parseDimensions(std::string str) {
    std::cout << "str:" << str << std::endl;
    std::string tmp;
    std::vector<int> items;
    int x, y;
    std::smatch match;
    bool thing = std::regex_search(str, match, boardDimensions);
    if (std::regex_search(str, match, boardDimensions)) {
        x = std::stoi(match.str(1));
        y = std::stoi(match.str(2));
    }

    items.emplace_back(x);
    items.emplace_back(y);
    std::cout << "x:" << x << "\ny:" << y << std::endl;

    return items;
}

bool utils::validateDirection(int input) {
    if (input != 1 && input !=2) {
        std::cout << "Invalid direction entered. Input must be 1 or 2." << std::endl;
        return false;
    }
    return true;
}

std::vector<std::string> utils::getCoordinatesList(int shipLength, std::string coordinates, int direction) {
    std::vector<std::string> coordinatesList;
    std::vector<int> headCoordinates = parseCoordinates(coordinates);
    int x = headCoordinates.at(0);
    int y = headCoordinates.at(1) + 1;
    for (int i = 0; i < shipLength; i++) {
        int newX, newY;
        // if the direction is horizontal
        if (direction == 1) {
            newX = x + i;
            newY = y;
        } else {
            newX = x;
            newY = y + i;
        }
        std::string xAlpha = headerAlphas.at(newX);
        std::string newCoordinates = xAlpha + std::to_string(newY);
        coordinatesList.push_back(newCoordinates);
    }
    return coordinatesList;
}

std::string utils::generateRandomCoordinates(int xLimit, int yLimit) {
    srand(time(NULL));
    std::string randX = headerAlphas.at(randomBetween19937(0, xLimit));
    int randY = randomBetween19937(1, yLimit);
//    std::cout << "RAND Y." << randY << std::endl;

    return randX + std::to_string(randY);

}

int utils::randomBetween19937(int low, int high) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(low, high);

    return dist6(rng);
}

bool utils::validateDimensions(std::string str) {
    return std::regex_match(str, boardDimensions);

}
