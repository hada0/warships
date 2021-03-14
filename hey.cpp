//
// Created by HongAnn Dao on 09/03/2021.
//

#include <iostream>
#include "mini/ini.h"
#include "hey.h"

mINI::INIStructure hey::readIni(){
    mINI::INIFile file("cconfig.ini");
    mINI::INIStructure ini;
    try {
        bool readSuccess = file.read(ini);
        std::cout << "INI file read successfully\n\n";
        return ini;
    }catch (std::exception e) {
        std::cout << "Error reading INI file\nGot following error: ";
        std::cerr << e.what();
    }
}