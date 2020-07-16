//
// Created by sufyan kerboua on 15/07/2020.
//

#include "RPNProcessor.hpp"

/*
 * Public Methods
 */

Tools::errorEnum RPNProcessor::setInput(const std::string &input)
{
    if (_tools.isOperand(input))
        this->setInputInStack(input);
    else if (_tools.isOperator(input))
        return (this->calculationFromOperator(input));
    else
        return Tools::errorEnum::BadSyntax;
    return Tools::errorEnum::Success;
}

void RPNProcessor::clearStack()
{
    while (_stackOperands.size() > 0) {
        _stackOperands.top();
        _stackOperands.pop();
    }
}

/*
 * Private Methods
 */

Tools::errorEnum RPNProcessor::calculationFromOperator(const std::string &input)
{
    if (_stackOperands.size() < 2)
        return Tools::errorEnum::MissingOperand;

    if (!this->setCurrentOperatorFromString(input))
        return Tools::errorEnum::DivisionByZero;

    this->getOperandsFromStack();
    this->calculateOperands();
    this->setResultInStack();

    return Tools::errorEnum::Success;
}

bool RPNProcessor::setCurrentOperatorFromString(const std::string myOperator)
{
    if ((myOperator[0] == '/') && (_stackOperands.top() == 0))
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

void RPNProcessor::calculateOperands()
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
    }
    std::cout << this->getResult() << std::endl;
}
