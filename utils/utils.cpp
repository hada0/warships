//
// Created by HongAnn Dao on 02/03/2021.
//

#include <string>
#include <iostream>
#include <regex>
#include "utils.h"

std::vector<std::string> utils::split(std::string &str, const std::string &delim) {
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

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

std::vector<int> utils::parseCoordinates(std::string coordinatesStr) {
    std::string tmpX;
    std::vector<int> coord;
    int x, y;
    std::smatch match;
    if (std::regex_search(coordinatesStr, match, coordinates)) {
        x = convertAlphaToInt(match.str(1));
        y = std::stoi(match.str(2));
    }
    coord.emplace_back(x);
    coord.emplace_back(y);
//    std::cout << "x:" << x << "\ny:" << y << std::endl;

    return std::vector<int>();
}
