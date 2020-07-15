//
// Created by sufyan kerboua on 14/07/2020.
//

#include "Core.hpp"

Core::Core() : _running(true), _calculationAuthorization(false)
{
}

void Core::run()
{
    std::string line;

    std::system("clear");
    while (this->_running) {

        std::cout << "RPN Calculator >";
        _interpreter.getNextLine();
        if (_tool.isOperandOrOperator(_interpreter.getLine())) {
            if (!_rpnProcessor.setInput(_interpreter.getLine()))
                std::cout << "Impossible d'effectuer le calcul, veuillez d'abord entrer 2 operandes.";
        } else
            std::cout << "Mauvaise syntax, veuillez recommencer votre expression." << std::endl;


        //if (_interpreter.getNextLineToArray())
            //_rpnProcessor.calculationFromList(_interpreter.getExpressionList());

//        if (_calculationAuthorization)
            //_rpnProcessor.calculationFromArray(_interpreter.getExpressionArray());

//        if (command quit is called)
//        this->_running = false;
//        return;
    }
}