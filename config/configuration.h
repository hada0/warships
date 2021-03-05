//
// Created by HongAnn Dao on 02/03/2021.
//

#ifndef WARSHIPS_CONFIGURATION_H
#define WARSHIPS_CONFIGURATION_H

#include <map>
#include <vector>
#include "../board/board.h"

class configuration {
private:
    bool mines{};
    bool salvo{};
    bool autoplaceAll{};
    int height{};
    int width{};
public:
    int getHeight() const;

    int getWidth() const;

public:
    std::vector<node> & getShipLibrary();

private:
    std::vector<node> shipLibrary;

public:
    configuration();

    void parse_config(std::string fileName);

    void default_config();

};

#endif //WARSHIPS_CONFIGURATION_H
