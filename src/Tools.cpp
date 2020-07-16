//
// Created by sufyan kerboua on 15/07/2020.
//

#include "Tools.hpp"

Tools::Tools()
{
    this->initializeErrorMap();
}

void Tools::initializeErrorMap()
{
    _errorMap[0] = std::make_pair("none", errorEnum::Success);
    _errorMap[1] = std::make_pair("bad_syntax", errorEnum::BadSyntax);
    _errorMap[2] = std::make_pair("missing_operand", errorEnum::MissingOperand);
    _errorMap[3] = std::make_pair("division_by_zero", errorEnum::DivisionByZero);
}

void Tools::setErrorToken(Tools::errorEnum errorToken)
{
    for (auto val: _errorMap)
        if(val.second == errorToken)
            _errorToken = val.first;
}

std::string Tools::getErrorToken()
{
    return _errorToken;
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