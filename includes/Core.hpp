//
// Created by sufyan kerboua on 14/07/2020.
//

#ifndef RPN_CALCULATOR_CORE_H
#define RPN_CALCULATOR_CORE_H

#include <iostream>
#include <string>
#include "Tools.hpp"
#include "Interpreter.hpp"
#include "RPNProcessor.hpp"

class Core {

public:
    Core();
    ~Core() {};
    void run();

protected:
    // todo à remove
    inline int coreTest() { return 12; };

    Interpreter _interpreter;
    RPNProcessor _rpnProcessor;
    Tools       _tool;
    bool _running;
    bool _calculationAuthorization;
};


#endif //RPN_CALCULATOR_CORE_H
