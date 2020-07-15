//
// Created by sufyan kerboua on 15/07/2020.
//

#ifndef RPN_CALCULATOR_RPNPROCESSOR_H
#define RPN_CALCULATOR_RPNPROCESSOR_H

#include <iostream>
#include <vector>
#include <string>

class RPNProcessor
{
public:
    RPNProcessor();
    ~RPNProcessor() {};

private:
    double  expressionCalculation(std::vector<std::string> expression);
    double  _number1;
    double  _number2;
    char    operand;
    double  _result;
};

#endif //RPN_CALCULATOR_RPNPROCESSOR_H
