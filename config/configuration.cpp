//
// Created by HongAnn Dao on 02/03/2021.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "configuration.h"
#include "../mini/ini.h"
#include "../utils/utils.h"
#include "../board/board.h"

void configuration::defaultConfig() {
    height = 8;
    width = 8;

//    shipLibrary.emplace_back("CARRIER", 5);
//    shipLibrary.emplace_back("CARRIER", 5);
//    shipLibrary.emplace_back("BATTLESHIP", 4);
//    shipLibrary.emplace_back("BATTLESHIP", 4);
//    shipLibrary.emplace_back("DESTROYER", 3);
    shipLibrary.emplace_back("DESTROYER", 3);
//    shipLibrary.emplace_back("SUBMARINE", 3);
//    shipLibrary.emplace_back("SUBMARINE", 3);
//    shipLibrary.emplace_back("PATROL", 2);
    shipLibrary.emplace_back("PATROL", 2);
}

configuration::configuration() = default;

std::vector<ship> &configuration::getShipLibrary() {
    return shipLibrary;
}

int configuration::getHeight() const {
    return height;
}

int configuration::getWidth() const {
    return width;
}

void configuration::parseConfig(std::string fileName) {

    std::regex iniFormat =std::regex("([^\\s]+)[ ]?=\\s?(.*[^=])");
    std::ifstream configFile;
    configFile.open(fileName, std::ifstream::in);
    std::string line;

    while (!configFile.eof()) {
        getline(configFile, line);

        // Ignore line if it is a new line.
        if (line.empty()) {
            continue;
        }
        // Ignore line if it is a comment.
        if (line.at(0) == ';') {
            continue;
        }

        std::smatch match;
        if (std::regex_search(line, match, iniFormat)) {
            std::string key = match.str(1);
            std::string value = match.str(2);
            iniContents.insert(std::pair<std::string, std::string>{key, value});
        } else {
            std::cout << "Error in parsing configuration file. Please check it complies with format instructions.";
            exit(EXIT_FAILURE);
        }
    }
    configFile.close();
}

void configuration::setupGameConfig() {
    std::string b = iniContents.at("Board");
    if (!utils::validateDimensions(b)) {
        std::cout << "Error in parsing board dimensions. Please check it complies with format instructions.";
        exit(EXIT_FAILURE);
    }
    width = utils::parseDimensions(b).at(0);
    height = utils::parseDimensions(b).at(1);
    if (width < 5 || width > 80 || height < 5 || height > 80) {
        std::cout << "Board dimensions out of range. Please check it complies with format instructions.";
        exit(EXIT_FAILURE);
    }
    carrierLength = std::stoi(iniContents.at("CarrierLength"));
    carrierQuantity = std::stoi(iniContents.at("CarrierQuantity"));
    battleshipLength = std::stoi(iniContents.at("BattleshipLength"));
    battleshipQuantity = std::stoi(iniContents.at("BattleshipQuantity"));
    destroyerLength = std::stoi(iniContents.at("DestroyerLength"));
    destroyerQuantity = std::stoi(iniContents.at("DestroyerQuantity"));
    submarineLength = std::stoi(iniContents.at("SubmarineLength"));
    submarineQuantity = std::stoi(iniContents.at("SubmarineQuantity"));
    patrolLength = std::stoi(iniContents.at("PatrolLength"));
    patrolQuantity = std::stoi(iniContents.at("PatrolQuantity"));

    addToShipLibrary("CARRIER", carrierLength, carrierQuantity);
    addToShipLibrary("BATTLESHIP", battleshipLength, battleshipQuantity);
    addToShipLibrary("DESTROYER", destroyerLength, destroyerQuantity);
    addToShipLibrary("SUBMARINE", submarineLength, submarineQuantity);
    addToShipLibrary("PATROL", patrolLength, patrolQuantity);
}

void configuration::addToShipLibrary(std::string type, int length, int quantity) {
    for (int i = 0; i < quantity; i++) {
        shipLibrary.emplace_back(type, length);
    }
}


