//
// Created by sufyan kerboua on 15/07/2020.
//

#pragma once

#include <regex>
#include <array>

class Tools {
public:
    Tools();
    ~Tools() {};

    enum class errorEnum
    {
        Success             = 0,
        BadSyntax           = 1,
        MissingOperand      = 2,
        DivisionByZero      = 3
    };

    bool            isOperandOrOperator(std::string expression);
    bool            isOperand(std::string expression);
    bool            isOperator(std::string expression);
    std::string     &removeUnnecessarySpace(std::string &line);
    void            initializeErrorMap();
    void            setErrorToken(Tools::errorEnum errorToken);
    std::string     getErrorToken();

private:
    std::array<std::pair<std::string, Tools::errorEnum>, 4> _errorMap;
    std::string                                             _errorToken;

};
