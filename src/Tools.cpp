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

/**
 * @brief Fonction permettant de checker si une string est une opérande simple ou un opérateur
   @param std::string expression | string devant contenir une opérande ou un opérator valide
   @return Bool | Boolean permettant de savoir si la string est une opérande
   */
bool Tools::isOperandOrOperator(std::string expression)
{
    if (this->isOperator(expression) || this->isOperand(expression))
        return true;
    return false;
}

/**
 * @brief Fonction ayant pour but de supprimer tout espace doublon, pouvant fausser l'interpretation de la ligne.
   @param Std::string &line | String à traiter
   @return Std::string &line | String épuré
   */
std::string & Tools::removeUnnecessarySpace(std::string &line)
{
    int lengthLine = line.length();

    for (int i = 0; i < lengthLine; i++) {
        while (isspace(line[i]) && isspace(line[i + 1])) {
            line.erase(i, 1);
        }
    }

    if (isspace(line[line.length() - 1]))
        line.erase(line.length() - 1, 1);

    if (isspace(line[0]))
        line.erase(0, 1);

    return line;
}