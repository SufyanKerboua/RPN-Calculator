//
// Created by sufyan kerboua on 14/07/2020.
//

#include <iostream>
#include <exception>
#include "Core.hpp"

int main() {

    try {
        Core core;
        core.run();
    } catch (const std::exception &e) {
        std::cerr << "Catched an exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}