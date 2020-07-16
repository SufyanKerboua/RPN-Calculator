//
// Created by sufyan kerboua on 15/07/2020.
//

#include "RPNProcessor.hpp"

RPNProcessor::RPNProcessor()
{
}

bool RPNProcessor::setInput(const std::string &input)
{
    if (_tools.isOperand(input))
        this->setInputInStack(input);
    else
        return (this->calculationFromOperator(input));
    return true;
}

bool RPNProcessor::calculationFromOperator(const std::string &input)
{
    if (_stackOperands.size() < 2)
        return false;
    this->setCurrentOperatorFromString(input);
    this->getOperandsFromStack();
    this->calculateOperands();
    this->setResultInStack();
    return true;
}

bool RPNProcessor::setCurrentOperatorFromString(const std::string myOperator)
{
    if (!_tools.isOperator(myOperator))
        return false;
    _currentOperator = myOperator[0];
    return true;
}

void RPNProcessor::getOperandsFromStack()
{
    this->setSecondOperand(_stackOperands.top());
    _stackOperands.pop();
    this->setFirstOperand(_stackOperands.top());
    _stackOperands.pop();
}

bool RPNProcessor::calculateOperands()
{
    switch (_currentOperator)
    {
        case '+':
            this->plusOperation();
            break;
        case '-':
            this->minusOperation();
            break;
        case '*':
            this->multiplyOperation();
            break;
        case '/':
            this->divideOperation();
            break;
        default:
            return false;
    }
    std::cout << this->getResult() << std::endl;
    return true;
}

void RPNProcessor::clearStack()
{
    while (_stackOperands.size() > 0) {
        _stackOperands.top();
        _stackOperands.pop();
    }
}

/*
 * Liste Opération
 */

bool RPNProcessor::plusOperation()
{
    _result = _firstOperand + _secondOperand;
    return true;
}

bool RPNProcessor::minusOperation()
{
    _result = _firstOperand - _secondOperand;
    return true;
}

bool RPNProcessor::multiplyOperation()
{
    _result = _firstOperand * _secondOperand;
    return true;
}

bool RPNProcessor::divideOperation()
{
    if (_secondOperand != 0)
        _result = _firstOperand / _secondOperand;
    else
        return false;
    return true;
}

/*
 * Setter
 */

void RPNProcessor::setFirstOperand(double firstOperand) {
    _firstOperand = firstOperand;
}

void RPNProcessor::setSecondOperand(double secondOperand) {
    _secondOperand = secondOperand;
}

/*
 * Getter
 */

double RPNProcessor::getResult() const {
    return _result;
}
