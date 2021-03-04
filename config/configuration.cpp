//
// Created by HongAnn Dao on 02/03/2021.
//

#include <iostream>
#include "configuration.h"
#include "../mini/ini.h"
#include "../common/common.h"
#include "../board/board.h"

void configuration::parse_config(std::string fileName) {
    mINI::INIFile file(fileName);
    mINI::INIStructure ini;
    bool read = file.read(ini);
    std::cout << "read" << read << std::endl;
    std::string m = ini.get("Configuration").get("Mines");
    std::istringstream(m) >> std::boolalpha >> mines;

    std::string s = ini.get("Configuration").get("Salvo");
    std::istringstream(s) >> std::boolalpha >> salvo;

    std::string aa = ini.get("Configuration").get("AutoplaceAll");
    std::istringstream(aa) >> std::boolalpha >> autoplaceAll;

//    std::string b = ini["Configuration"]["Board"];
//    std::string boardHeight = common::split(b, "x").at(0);
//    std::string boardWidth = common::split(b, "x").at(1);
//    gameBoard.setDimensions(std::stoi(boardHeight), std::stoi(boardWidth));

    std::vector<ship> shipsConfig;
    std::vector<int> shipsQuantity;
    bool hasSection = ini.has("ship_definition");

    std::cout << hasSection << std::endl;


    // Ensure there are only 5 ships defined (no duplicates)
    std::cout << ini["Ship_Definition"].size() << std::endl;
    if (ini["Ship Definition"].size() != 5) {
        std::cout << "Invalid Ship Definition, check there are no duplicates and restart other default options are used." << std::endl;
    }

    for (auto it : ini) {
        if (it.first == "Configuration") {
            continue;
        }
        std::cout << " hey " << std::endl;

        if (it.first == "Ship_Definition") {
            auto collection = it.second;
            for (auto it2 : collection) {
                shipsConfig.emplace_back(it2.first, std::stoi(it2.second));
            }
        }
        if (it.first == "Ship_Library") {
            auto collection = it.second;
            for (auto it2 : collection) {
                shipsQuantity.push_back(std::stoi(it2.second));
            }
        }
    }
    std::cout << " hey " << std::endl;

    for (int i = 0; i < shipsConfig.size(); i++) {
        std::cout << shipsConfig.at(i).type << "and " << shipsQuantity.at(i) << std::endl;
        for (int j = 0; j < shipsQuantity.at(i); j++) {
            shipLibrary.push_back(shipsConfig.at(i));
        }
    }
}

void configuration::default_config() {
    mines = false;
    salvo = false;
    autoplaceAll = false;
    gameBoard.setDimensions(8,8);

    std::vector<ship> ships;
    shipLibrary.emplace_back("CARRIER", 5);
    shipLibrary.emplace_back("CARRIER", 5);
    shipLibrary.emplace_back("BATTLESHIP", 4);
    shipLibrary.emplace_back("BATTLESHIP", 4);
    shipLibrary.emplace_back("DESTROYER", 3);
    shipLibrary.emplace_back("DESTROYER", 3);
    shipLibrary.emplace_back("SUBMARINE", 3);
    shipLibrary.emplace_back("SUBMARINE", 3);
    shipLibrary.emplace_back("PATROL", 2);
    shipLibrary.emplace_back("PATROL", 2);
}

configuration::configuration() = default;

board configuration::getGameBoard() {
    return board();
}

std::vector<ship> &configuration::getShipLibrary() {
    return shipLibrary;
}
