//
// Created by HongAnn Dao on 02/03/2021.
//

#include "configuration.h"
#include "mini/ini.h"
#include "helper.h"

void configuration::parse_config(std::string fileName) {
    mINI::INIFile file("config.ini");
    mINI::INIStructure ini;
    file.read(ini);

    std::string m = ini["Congiguration"]["Mines"];
    std::istringstream(m) >> std::boolalpha >> mines;

    std::string s = ini["Congiguration"]["Salvo"];
    std::istringstream(s) >> std::boolalpha >> salvo;

    std::string aa = ini["Congiguration"]["AutoplaceAll"];
    std::istringstream(aa) >> std::boolalpha >> autoplaceAll;

    std::string b = ini["Congiguration"]["Board"];
    std::string boardHeight = helper::split(b, "x").at(0);
    std::string boardWidth = helper::split(b, "x").at(1);

    board = board(std::stoi(boardHeight), std::stoi(boardWidth));
}
