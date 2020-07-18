//
// Created by sufyan kerboua on 15/07/2020.
//

#include "RPNProcessor.hpp"

/*
 * Public Methods
 */

/**
 * @brief Fonction ayant pour but de récupérer une expression,
 * checker si elle correspond à un opérateur ou un opérande,
 * puis la calculer si cela est possible, puis d'afficher le resultat
 *
   @param const std::string &input | l'expression donnée
   @return Tools::errorEnum | renvoie un enum permettant
   de savoir si une erreur est survenu ou non
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

/**
 * @brief Fonction ayant pour but de vider la stack de la calculatrice
 *
   @param none
   @return void
   */
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

/**
 * @brief Fonction ayant pour but de calculer les 2 dernieres opérandes
 * avec l'opérateur donnée
 *
   @param const std::string &myOperator | string devant être un opérateur
   @return Tools::errorEnum | renvoie un enum permettant
   de savoir si une erreur est survenu ou non
   */
Tools::errorEnum RPNProcessor::calculationFromOperator(const std::string &myOperator)
{
    if (_stackOperands.size() < 2)
        return Tools::errorEnum::MissingOperand;

    if (!this->setCurrentOperatorFromString(myOperator))
        return Tools::errorEnum::DivisionByZero;

    this->getOperandsFromStack();
    this->calculateOperands();
    this->setResultInStack();

    return Tools::errorEnum::Success;
}

/**
 * @brief Fonction ayant pour but de sauvegarder l'opérateur actuel dans la classe
 *
   @param const std::string myOperator | string devant être un opérateur
   @return bool | renvoie un boolean  pouvant être true si l'opérateur à bien été sauvegarder
   et false si une division par 0 est demandé
   */
bool RPNProcessor::setCurrentOperatorFromString(const std::string myOperator)
{
    if ((myOperator[0] == '/') && (_stackOperands.top() == 0))
        return false;
    _currentOperator = myOperator[0];
    return true;
}

/**
 * @brief Fonction ayant pour but de récupérer les 2 dernieres opérandes et de les enlever de la stack
 *
   @param None
   @return void
   */
void RPNProcessor::getOperandsFromStack()
{
    this->setSecondOperand(_stackOperands.top());
    _stackOperands.pop();
    this->setFirstOperand(_stackOperands.top());
    _stackOperands.pop();
}

/**
 * @brief Fonction ayant pour but de lancer l'opération demandé avec ces opérandes
 *
   @param None
   @return void
   */
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
