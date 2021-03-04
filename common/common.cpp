//
// Created by HongAnn Dao on 02/03/2021.
//

#include <string>
#include <iostream>
#include "common.h"

std::vector<std::string> common::split(std::string &str, const std::string &delim) {
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

void clearConsole() {
    std::cout << "\x1B[2J\x1B[H";
}