//
// Created by sufyan kerboua on 14/07/2020.
//

#pragma once

#include <iostream>
#include <string>
#include <map>

#include "Tools.hpp"
#include "ConfigLoader.hpp"
#include "RPNProcessor.hpp"

using commandFunctor = std::function<void(void)>;

class Core {

public:
    explicit Core();
    ~Core() = default;
    void                                    run();

private:
    void                                    setCommands();
    void                                    getNextLine();
    void                                    processNewLine();
    inline void                             executeCommands(const std::string &command) { _commandMap[command](); };
    void                                    printErrorMessage();

protected:
    // Permettant de tester la classe
    bool                                    isCommand(const std::string &param);

private:
    bool                                    _running;
    std::string                             _language;
    std::string                             _line;
    Tools                                   _tools;
    RPNProcessor                            _rpnProcessor;
    ConfigLoader                            _config;
    std::map<std::string, commandFunctor>&  _commandMap;
};
