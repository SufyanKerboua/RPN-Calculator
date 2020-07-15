//
// Created by sufyan kerboua on 15/07/2020.
//

#ifndef RPN_CALCULATOR_RPNPROCESSOR_H
#define RPN_CALCULATOR_RPNPROCESSOR_H

#include <iostream>
//#include <vector>
//#include <list>
#include <stack>
#include <string>
#include "Tools.hpp"

class RPNProcessor
{
public:
    RPNProcessor();
    ~RPNProcessor() {};

    bool    setInput(const std::string &input);
    void    setInputInStack(const std::string &input);
    bool    calculationFromOperator(const std::string &input);
    void    attributeStackToOperands();
    void    setResultInStack();


    bool    setCurrentOperatorFromString(const std::string myOperator);
    bool    calculateOperands();
    bool    plusOperation();
    bool    minusOperation();
    bool    multiplyOperation();
    bool    divideOperation();


private:
    Tools               _tools;
    std::stack<double>  _stackOperands;
    double              _firstOperand;
    double              _secondOperand;
    double              _result;
    char                _currentOperator;

public:
    /*
     * Setter
     */
    void    setFirstOperand(double firstOperand);
    void    setSecondOperand(double secondOperand);
public:
    /*
     * Getter
     */
    double  getResult() const;
};

#endif //RPN_CALCULATOR_RPNPROCESSOR_H
