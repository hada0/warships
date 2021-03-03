//
// Created by HongAnn Dao on 02/03/2021.
//

#include <iostream>
#include "board.h"
#include "mini/ini.h"
#include "helper.h"

//board* board::inst_ = nullptr;
//board *board::getInstance(const int height, const int width) {
//    if (inst_ == nullptr) {
//        inst_ = new board(height, width);
//    }
//    return inst_;
//}

//board board::configure(const std::string filename) {
//    std::string boardHeight;
//    std::string boardWidth;
//
//    mINI::INIFile file("config.ini");
//    mINI::INIStructure ini;
//    file.read(ini);
//    std::string &boardDimensions = ini["Configuration"]["Board"];
//
//    if (!board::validate(boardDimensions)) {
//        std::cout << "invalid dimensions, using default board dimensions 8x8" << std::endl;
//        std::string boardHeight = "8";
//        std::string boardWidth =  "8";
//    } else {
//        std::string boardHeight = helper::split(boardDimensions, "x").at(0);
//        std::string boardWidth = helper::split(boardDimensions, "x").at(1);
//    }
//
//    return board(std::stoi(boardHeight), std::stoi(boardWidth));
//}
//
bool board::validate(std::string dimensions) {
    if (dimensions.find("x") != std::string::npos) {
        return true;
    }
    return false;
}
