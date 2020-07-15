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

void RPNProcessor::setResultInStack()
{
    _stackOperands.push(this->getResult());
}

bool RPNProcessor::calculateOperands()
{
    switch (this->_currentOperator)
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
    std::cout << "Result : " << this->getResult() << std::endl;
    return true;
}

//

bool RPNProcessor::setCurrentOperatorFromString(const std::string myOperator)
{
    if (!_tools.isOperator(myOperator))
        return false;
    this->_currentOperator = myOperator[0];
    return true;
}

void RPNProcessor::setInputInStack(const std::string &input)
{
    double newOperand = std::stod(input);
    _stackOperands.push(newOperand);
}

bool RPNProcessor::calculationFromOperator(const std::string &input)
{
    if (_stackOperands.size() < 2)
        return false;
    this->setCurrentOperatorFromString(input);
    this->attributeStackToOperands();
    this->calculateOperands();
    this->setResultInStack();
    return true;
}

void RPNProcessor::attributeStackToOperands()
{
    this->setSecondOperand(_stackOperands.top());
    _stackOperands.pop();
    this->setFirstOperand(_stackOperands.top());
    _stackOperands.pop();
}

bool RPNProcessor::plusOperation()
{
    std::cout << "In plusOperation with x : " << this->_firstOperand << ", y : " << this->_secondOperand << std::endl;
    this->_result = this->_firstOperand + this->_secondOperand;
    return true;
}

bool RPNProcessor::minusOperation()
{
    std::cout << "In minusOperation with x : " << this->_firstOperand << ", y : " << this->_secondOperand << std::endl;
    this->_result = this->_firstOperand - this->_secondOperand;
    return true;
}

bool RPNProcessor::multiplyOperation()
{
    std::cout << "In multiplyOperation with x : " << this->_firstOperand << ", y : " << this->_secondOperand << std::endl;
    this->_result = this->_firstOperand * this->_secondOperand;
    return true;
}

bool RPNProcessor::divideOperation()
{
    std::cout << "In divideOperation with x : " << this->_firstOperand << ", y : " << this->_secondOperand << std::endl;
    if (this->_secondOperand != 0)
        this->_result = this->_firstOperand / this->_secondOperand;
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
