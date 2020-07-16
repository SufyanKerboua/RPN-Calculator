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

    bool            setInput(const std::string &input);
    inline void     setInputInStack(const std::string &input) { _stackOperands.push(std::stod(input)); };
    inline void     setResultInStack() { _stackOperands.push(this->getResult()); };
    bool            calculationFromOperator(const std::string &input);

    // todo mettre de method en privé et les tester
    void            clearStack();

    bool            setCurrentOperatorFromString(const std::string myOperator);
    bool            calculateOperands();
    bool            plusOperation();
    bool            minusOperation();
    bool            multiplyOperation();
    bool            divideOperation();

private:
    void            getOperandsFromStack();

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
