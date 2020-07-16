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
    RPNProcessor();
    ~RPNProcessor() {};

    bool            setInput(const std::string &input);
    void            clearStack();

private:
    inline void     setInputInStack(const std::string &input) { _stackOperands.push(std::stod(input)); };
    bool            calculationFromOperator(const std::string &input);

    bool            setCurrentOperatorFromString(const std::string myOperator);
    void            getOperandsFromStack();
    bool            calculateOperands();
    inline void     setResultInStack() { _stackOperands.push(this->getResult()); };

    bool            plusOperation();
    bool            minusOperation();
    bool            multiplyOperation();
    bool            divideOperation();

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
    double  getResult() const;
    /*
     * Setter
     */
    void    setFirstOperand(double firstOperand);
    void    setSecondOperand(double secondOperand);
};
