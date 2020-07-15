//
// Created by sufyan kerboua on 14/07/2020.
//

#ifndef RPN_CALCULATOR_INTERPRETER_H
#define RPN_CALCULATOR_INTERPRETER_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Interpreter {
public:
    Interpreter();
    ~Interpreter() {};
    std::string getNextLine();

protected:
//    std::vector<std::string> parseSpaceDelimiters(std::string &line);
    std::string parseSpaceDelimiters(std::string &line);
};


#endif //RPN_CALCULATOR_INTERPRETER_H
