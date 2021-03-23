//
// Created by HongAnn Dao on 02/03/2021.
//
// Utils contains static tools that are used across the game including parsing structures and validating data entries.

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

    // Converts coordinates to uppercase for handling.
    static std::string coordinatesToUpper(std::string coordinatesStr);

    // Checks the coordinates are in the correct format. Correct format examples include A3, G1 etc. depending on the
    // size of the board.
    static bool validateCoordinatesFormat(std::string coordinatesStr);

    // Checks the defined ships in the config fits on the defined board.
    static bool validateMaxShipsOnBoard(int boardArea, int totalShipsArea);

    // Checks direction is 1 (for horizontal) or 2 (for vertical).
    static bool validateDirection(int input);

    // Checks dimension are within the minimum bounds of 5x5 and maximum bounds of 80x80.
    static bool validateDimensions(std::string str);

    // Retrieves dimensions provided by the config file.
    static std::vector<int> parseDimensions(std::string str);

    // Converts coordinates to integers from a user entered string.
    static std::vector<int> parseCoordinates(std::string str);

    // Converts the alpha header to an integer representation.
    static int convertAlphaToInt(std::string alpha);

    // Returns a list of coordinates that will be occupied with the given ship.
    static std::vector<std::string> getCoordinatesList(int shipLength, std::string coordinates, int direction);

    // Generate random valid coordinates depending on the size of the board.
    static std::string generateRandomCoordinates(int xLimit, int yLimit);

    // Helper function to ensure the random generator is seeded correctly.
    static int randomBetween19937(int low, int high);

};