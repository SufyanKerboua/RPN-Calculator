//
// Created by sufyan kerboua on 14/07/2020.
//

#pragma once

#include <iostream>
#include <string>
#include "Tools.hpp"
#include "Interpreter.hpp"
#include "ConfigLoader.hpp"

class Core {

public:
    Core();
    ~Core() {};
    void run();
protected:
    // todo à remove
    inline int coreTest() { return 12; };
private:
    Interpreter     _interpreter;
    ConfigLoader    _config;
    bool            _running;
};
