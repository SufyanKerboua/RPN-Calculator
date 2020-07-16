//
// Created by sufyan kerboua on 14/07/2020.
//

#include "Core.hpp"

static std::map<std::string, std::function<void(void)>> COMMANDS;

static const std::string configFilePath("./config.yml");

Core::Core(): _interpreter(COMMANDS, configFilePath), _config(configFilePath), _running(true)
{
}

void Core::run()
{
    _interpreter.executeCommands("clear");
    while (_running) {
        std::cout << _config["prompt"].as<std::string>();
        _interpreter.getNextLine();
        _interpreter.processNewLine();
    }
}