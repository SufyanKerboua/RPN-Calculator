//
// Created by sufyan kerboua on 15/07/2020.
//

#pragma once

#include <iostream>
#include <stack>
#include <string>
#include "Tools.hpp"

class RPNProcessor
{
public:
    RPNProcessor() {};
    ~RPNProcessor() {};

    Tools::errorEnum    setInput(const std::string &input);
    void                clearStack();

private:
    Tools::errorEnum    calculationFromOperator(const std::string &myOperator);
    bool                setCurrentOperatorFromString(const std::string myOperator);
    void                getOperandsFromStack();
    void                calculateOperands();
    inline void         setInputInStack(const std::string &input) { _stackOperands.push(std::stod(input)); };
    inline void         setResultInStack() { _stackOperands.push(this->getResult()); };

    inline void         plusOperation() { _result = _firstOperand + _secondOperand; };
    inline void         minusOperation() { _result = _firstOperand - _secondOperand; };
    inline void         multiplyOperation() { _result = _firstOperand * _secondOperand; };
    inline void         divideOperation() { _result = _firstOperand / _secondOperand; };

private:
    Tools               _tools;
    std::stack<double>  _stackOperands;
    double              _firstOperand;
    double              _secondOperand;
    double              _result;
    char                _currentOperator;

public:
    /*
     * Getter
     */
    inline double       getResult() const { return _result; };
    /*
     * Setter
     */
    inline void         setFirstOperand(double firstOperand) { _firstOperand = firstOperand; };
    inline void         setSecondOperand(double secondOperand) { _secondOperand = secondOperand; };
};
