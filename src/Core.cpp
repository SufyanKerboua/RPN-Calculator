//
// Created by sufyan kerboua on 14/07/2020.
//

#include "Core.hpp"

std::map<std::string, std::function<void(void)>> COMMANDS;

Core::Core(): _interpreter(COMMANDS), _running(true)
{
}

void Core::run()
{
    std::string line;

    _interpreter.executeCommands("clear");
    while (_running) {
        std::cout << "RPN Calculator >";
        _interpreter.getNextLine();
        _interpreter.processNewLine();
    }
}