//
// Created by sufyan kerboua on 14/07/2020.
//

#ifndef RPN_CALCULATOR_CORE_H
#define RPN_CALCULATOR_CORE_H

#include <iostream>
#include <string>
#include "Interpreter.hpp"

class Core {

public:
    Core();
    ~Core() {}
    void run();

protected:
    int coreTest() { return 12; };

    Interpreter _interpreter;
    bool _running;
};


#endif //RPN_CALCULATOR_CORE_H
