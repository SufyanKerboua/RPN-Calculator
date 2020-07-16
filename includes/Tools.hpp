//
// Created by sufyan kerboua on 15/07/2020.
//

#pragma once

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
