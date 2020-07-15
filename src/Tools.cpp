//
// Created by sufyan kerboua on 15/07/2020.
//

#include "Tools.hpp"
#include <iostream>

Tools::Tools()
{
}

/**
 * @brief Fonction permettant de checker si une string est un opérateur simple ou non
   @param std::string expression | string devant contenir un opérateur simple et valide
   @return Bool | Boolean permettant de savoir si la string est un opérateur
   */
bool Tools::isOperator(std::string expression) {

    std::string basicOperator[] = {"+", "-", "*", "/"};

    for (int i = 0; i < 4 ; i++) {
        if (basicOperator[i].compare(expression) == 0)
            return true;
    }
    return false;
}

/**
 * @brief Fonction permettant de checker si une string est une opérande simple ou non
   @param std::string expression | string devant contenir une opérande et valide
   @return Bool | Boolean permettant de savoir si la string est une opérande
   */
bool Tools::isOperand(std::string expression) {

    std::regex e("^[-]?[0-9]+([.][0-9]+)?");
    if ((!expression.empty()) && (std::regex_match(expression, e)))
        return true;
    return false;
}

bool Tools::isOperandOrOperator(std::string expression)
{
    if (this->isOperator(expression) || this->isOperand(expression))
        return true;
    return false;
}
