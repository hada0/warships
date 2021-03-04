#include <iostream>
#include "config/configuration.h"
#include "player/player.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    configuration gameConfig = configuration();
    gameConfig.default_config();

    player p1(gameConfig);
    p1.setup();
    p1.displayKey();

    std::cout << "Bye, World!" << std::endl;

    return 0;
}