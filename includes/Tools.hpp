//
// Created by sufyan kerboua on 15/07/2020.
//

#ifndef RPN_CALCULATOR_TOOLS_HPP
#define RPN_CALCULATOR_TOOLS_HPP

#include <regex>

class Tools {
public:
    Tools();
    ~Tools() {};

    bool            isOperandOrOperator(std::string expression);
    bool            isOperand(std::string expression);
    bool            isOperator(std::string expression);
    std::string     &removeUnnecessarySpace(std::string &line);
};

#endif //RPN_CALCULATOR_TOOLS_HPP
