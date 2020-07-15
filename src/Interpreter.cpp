//
// Created by sufyan kerboua on 14/07/2020.
//

#include "Interpreter.hpp"

Interpreter::Interpreter()
{
}

/**
 * @brief Fonction ayant pour but de récupérer la derniere ligne que l'utilisateur à pu taper
   @param None
   @return void
   */
void Interpreter::getNextLine()
{
    getline(std::cin, _line);
    this->removeUnnecessarySpace((std::string &) _line);
    // todo remove
    //std::cout << _line << std::endl;
}

// todo move to utils
/**
 * @brief Fonction ayant pour but de supprimer tout espace doublon, pouvant fausser l'interpretation de la ligne.
   @param Std::string &line | String à traiter
   @return Std::string &line | String épuré
   */
std::string & Interpreter::removeUnnecessarySpace(std::string &line)
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

/**
 * @brief Fonction ayant pour but de générer un tableau grâce à une string et un délimiteur défini
   @param Std::string str, | String à traiter
   @param Char delimiter, | Character permettant de délimiter la string
   @return std::vector<std::string> | Tableau répértoriant tous les éléments de la string précédente, sans les délimiteurs
   */
std::list<std::string> & Interpreter::splitStringToListDelimiters(std::string str, char delimiter) {
    size_t pos = 0;
    std::string token;

    while ( (((pos = str.find(delimiter)) != std::string::npos))) {
        token = str.substr(0, pos);
        _expressionList.push_back(token);
        str.erase(0, pos + 1);
    }
    _expressionList.push_back(str);
    return _expressionList;
}

/**
 * @brief Fonction ayant pour but de récupérer la derniere ligne que l'utilisateur à pu taper et la renvoyer sous la forme d'un tableau
   @param None
   @return Bool | Boolean permettant de savoir si l'utilisateur si une erreur est survenu ou non
   */
bool Interpreter::getNextLineToArray() {

    this->getNextLine();

    //this->splitStringToArrayDelimiters(std::string(_line), ' ');
    this->splitStringToListDelimiters(std::string(_line), ' ');

    // todo à remove
    //for (std::string s : _expressionArray) {
    for (std::string s : _expressionList) {
        std::cout << "|" << s ;
    }
    std::cout << "|" << std::endl;

    //if (!this->isRPNExpressionValid(_expressionArray))
    if (!this->isRPNExpressionValid(_expressionList))
        return false;
    return true;
}

/**
 * @brief Fonction permettant de checker si l'attribut _expressionArray est une expression RPN valide
   @param None
   @return Bool | Boolean permettant de savoir si l'expression RPN est bonne ou non
   */
bool Interpreter::isRPNExpressionValid(std::list<std::string> expressionArray) {
    int nbOperand = 0;
    int nbOperator = 0;
    int sizeExpression = expressionArray.size();

    if (expressionArray.size() < 3)
        return false;
    for (std::string expression : expressionArray) {
        if (!_tools.isOperandOrOperator(expression))
            return false;
        if (_tools.isOperator(expression))
            nbOperator++;
        else
            nbOperand++;
    }

    std::cout << "Total number of expression => " << sizeExpression << std::endl;
    std::cout << "Total Operands => " << nbOperand << std::endl;
    std::cout << "Total Operator => " << nbOperator << std::endl;

    std::cout << "Total number of expression / 2 => " << sizeExpression/2 << std::endl;

    if ((nbOperand < nbOperator) || (sizeExpression/2 != nbOperator))
        return false;

    return true;
}

/*
 * Getter
 */

const std::string &Interpreter::getLine() const {
    return _line;
}

const std::list<std::string> &Interpreter::getExpressionList() const {
    return _expressionList;
}
