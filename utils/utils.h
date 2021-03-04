//
// Created by HongAnn Dao on 02/03/2021.
//

#include <vector>
#include <regex>

#ifndef WARSHIPS_HELPER_H
#define WARSHIPS_HELPER_H

#endif //WARSHIPS_HELPER_H

const std::regex coordinates("([A-a-Z-z](?:[A-a-B-b])?)([1-9](?:[1-10])?)");

class utils {
public:
    static std::vector<std::string> split(std::string &str, const std::string& delim);
    static void clearConsole();
    static void clearBuffer();
    static bool validateCoordinatesFormat(std::string coordinatesStr);
    static std::vector<int> parseCoordinates(std::string coordinatesStr);
    static int convertAlphaToInt(std::string alpha);
};