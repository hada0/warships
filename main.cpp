#include <iostream>
#include "config/configuration.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    configuration gameConfig = configuration();
    gameConfig.parse_config("config.ini");

    std::cout << "Bye, World!" << std::endl;

    return 0;
}