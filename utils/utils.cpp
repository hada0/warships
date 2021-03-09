//
// Created by HongAnn Dao on 02/03/2021.
//

#include <string>
#include <iostream>
#include <regex>
#include "utils.h"

void utils::clearBuffer() {
    std::cin.clear();
    // Clears the std::cin state to ensure future IO ops work correctly
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    // Clears the cin buffer including new lines or additional characters
}

void clearConsole() {
    std::cout << "\x1B[2J\x1B[H";
}

bool utils::validateCoordinatesFormat(std::string coordinatesStr) {
    return std::regex_match(coordinatesStr, coordinates);
}

int utils::convertAlphaToInt(std::string alpha) {
    int value = 0;
    std::string str;
    const std::string alphas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for( char& c : alpha ) str = std::toupper(c);
    for (char& c : str) {
        const auto pos = alphas.find(c);
        if (pos != std::string::npos) {
            value = pos;
            break;
        }
    }
    return value;
}

std::vector<int> utils::parseCoordinates(std::string str) {
    std::string tmp;
    std::vector<int> items;
    int x, y;
    std::smatch match;
    if (std::regex_search(str, match, coordinates)) {
        x = convertAlphaToInt(match.str(1));
        y = std::stoi(match.str(2)) - 1;
    }

    items.emplace_back(x);
    items.emplace_back(y);
//    std::cout << "x:" << x << "\ny:" << y << std::endl;

    return items;
}

std::vector<int> utils::parseDimensions(std::string str) {
    std::cout << "str:" << str << std::endl;
    std::string tmp;
    std::vector<int> items;
    int x, y;
    std::smatch match;
    bool thing = std::regex_search(str, match, boardDimensions);
    std::cout << "match:" << thing << std::endl;
    if (std::regex_search(str, match, boardDimensions)) {
        std::cout << "x:" << match.str(1) << "\ny:" << match.str(2) << std::endl;
        x = std::stoi(match.str(1));
        y = std::stoi(match.str(2));
    }

    items.emplace_back(x);
    items.emplace_back(y);
    std::cout << "x:" << x << "\ny:" << y << std::endl;

    return items;}
