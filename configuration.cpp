//
// Created by HongAnn Dao on 02/03/2021.
//

#include <iostream>
#include <iomanip>
#include "configuration.h"
#include "mini/ini.h"
#include "utils/utils.h"
#include "board/board.h"

void configuration::parse_config(std::string fileName) {
    mINI::INIFile file("cconfig.ini");
    mINI::INIStructure ini;
    bool read = file.read(ini);
    std::cout << "read" << read << std::endl;

    bool hasConfig = ini.has("configuration");
    std::cout << "Has Section " << hasConfig << std::endl;

    size_t n_sections = ini.size();
    std::cout << "Has size " << n_sections << std::endl;

    std::string m = ini.get("configuration").get("mines");
    std::string mm = ini["configuration"]["mines"];
    std::cout << "mines: " << mm << std::endl;
    std::istringstream(m) >> std::boolalpha >> mines;

    std::string s = ini.get("configuration").get("salvo");
    std::istringstream(s) >> std::boolalpha >> salvo;

    std::string aa = ini.get("configuration").get("autoplace");
    std::istringstream(aa) >> std::boolalpha >> autoplaceAll;

//    std::string& thing = ini["configuration""board"];
    std::string thing = ini["lengths"]["Carrier"];
    std::cout << "thing: " << thing << std::endl;



//    std::string b = ini.get("configuration").get("board");
//    std::vector<int> dimensions = utils::parseDimensions(b);
//    int x = dimensions.at(0);
//    int y = dimensions.at(1);
//    if (x == 0 && y == 0) {
//        std::cout << "Invalid board dimensions. Using default dimensions 8x8." << std::endl;
//        height = 8;
//        width = 8;
//    } else {
//        height = y;
//        width = x;
//    }

//    std::vector<node> shipsConfig;
//    std::vector<int> shipsQuantity;
//    bool hasSection = ini.has("Ship_Definition");
//
//    std::cout << "Has Section " << hasSection << std::endl;
//
//    // Ensure there are only 5 ships defined (no duplicates)
////    std::cout << ini["Ship_Definition"].size() << std::endl;
////    if (ini["Ship Definition"].size() != 5) {
////        std::cout << "Invalid Ship Definition, check there are no duplicates and restart other default options are used." << std::endl;
////    }
//
//    for (auto it : ini) {
//        if (it.first == "Configuration") {
//            continue;
//        }
//        std::cout << " hey " << std::endl;
//
//        if (it.first == "Ship_Definition") {
//            auto collection = it.second;
//            for (auto it2 : collection) {
//                shipsConfig.emplace_back(it2.first, std::stoi(it2.second));
//            }
//        }
//        if (it.first == "Ship_Library") {
//            auto collection = it.second;
//            for (auto it2 : collection) {
//                shipsQuantity.push_back(std::stoi(it2.second));
//            }
//        }
//    }
//    std::cout << " hey " << std::endl;
//
//    for (int i = 0; i < shipsConfig.size(); i++) {
//        std::cout << shipsConfig.at(i).type << "and " << shipsQuantity.at(i) << std::endl;
//        for (int j = 0; j < shipsQuantity.at(i); j++) {
//            shipLibrary.push_back(shipsConfig.at(i));
//        }
//    }
}

void configuration::default_config() {
    mines = true;
    salvo = false;
    autoplaceAll = false;
    height = 8;
    width = 8;

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

std::vector<node> &configuration::getShipLibrary() {
    return shipLibrary;
}

int configuration::getHeight() const {
    return height;
}

int configuration::getWidth() const {
    return width;
}
