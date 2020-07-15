//
// Created by sufyan kerboua on 14/07/2020.
//

#include "Core.hpp"

Core::Core() : _running(true)
{
}

void Core::run()
{
    std::string line;
    while (this->_running) {
        std::cout << "RPN Calculator >" << this->coreTest();
        _interpreter.getNextLine();
        this->_running = false;
//        return;
    }
}