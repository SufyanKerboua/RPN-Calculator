//
// Created by sufyan kerboua on 14/07/2020.
//

#ifndef RPN_CALCULATOR_INTERPRETER_H
#define RPN_CALCULATOR_INTERPRETER_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include "Tools.hpp"

class Interpreter {
public:
    Interpreter();
    ~Interpreter() {};
    void getNextLine();
    bool getNextLineToArray();
    std::list<std::string> &splitStringToListDelimiters(std::string str, char delimiter);


protected:
    std::string &removeUnnecessarySpace(std::string &line);
    bool isRPNExpressionValid(std::list<std::string> expressionList);

private:
    std::string _line;
    std::list<std::string> _expressionList;
    Tools _tools;

public:
    // Getter
    const std::string &getLine() const;
    const std::list<std::string> &getExpressionList() const;
};


#endif //RPN_CALCULATOR_INTERPRETER_H
