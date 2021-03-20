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
const std::vector<std::string> headerAlphas = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O",
                                         "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "AA", "AB", "AC",
                                         "AD", "AE", "AF", "AG", "AH", "AI", "AJ", "AK", "AL", "AM", "AN", "AO",
                                         "AP", "AQ", "AR", "AS", "AT", "AU", "AV", "AW", "AX", "AY", "AZ", "BA",
                                         "BB", "BC", "BD", "BE", "BF", "BG", "BH", "BI", "BJ", "BK", "BL", "BM",
                                         "BN", "BO", "BP", "BQ", "BR", "BS", "BT", "BU", "BV", "BW", "BX", "BY",
                                         "BZ", "CA", "CB", "CC"};
class utils {
public:
    static void clearConsole();
    static void clearBuffer();
    static bool validateCoordinatesFormat(std::string coordinatesStr);
    static bool validateDirection(int input);
    static std::vector<int> parseDimensions(std::string str);
    static std::vector<int> parseCoordinates(std::string str);
    static int convertAlphaToInt(std::string alpha);
    // Returns a list of coordinates that will be occupied with the given ship.
    static std::vector<std::string> getCoordinatesList(int shipLength, std::string coordinates, int direction);
    static std::string generateRandomCoordinates(int xLimit, int yLimit);
};