//
// Created by HongAnn Dao on 02/03/2021.
//

#include <vector>
#include <regex>

#ifndef WARSHIPS_HELPER_H
#define WARSHIPS_HELPER_H

#endif //WARSHIPS_HELPER_H

const std::regex coordinates("([A-a-Z-z](?:[A-a-B-b])?)([1-9](?:[1-10])?)");
const std::regex boardDimensions("([1-9](?:[0-9])?)x([1-9](?:[0-9])?)");

class utils {
public:
    static void clearConsole();
    static void clearBuffer();
    static bool validateCoordinatesFormat(std::string coordinatesStr);
    static std::vector<int> parseDimensions(std::string str);
    static std::vector<int> parseCoordinates(std::string str);
    static int convertAlphaToInt(std::string alpha);
};