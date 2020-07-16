//
// Created by sufyan kerboua on 14/07/2020.
//

#ifndef RPN_CALCULATOR_INTERPRETER_H
#define RPN_CALCULATOR_INTERPRETER_H

#include <string>
//#include <list>
#include <map>
#include <iostream>
#include "Tools.hpp"
#include "RPNProcessor.hpp"

using commandFunctor = std::function<void(void)>;

class Interpreter {
public:
    explicit Interpreter(std::map<std::string, commandFunctor>& commandMap);
    ~Interpreter() = default;

    void            getNextLine();
    void            processNewLine();
    void            setCommands();
    bool            isCommand(const std::string &line);
    void            executeCommands(const std::string &line);

    std::string     &removeUnnecessarySpace(std::string &line);
    // Getter
    inline const    std::string &getLine() const { return _line; };
private:
    std::string     _line;
    Tools           _tools;
    RPNProcessor    _rpnProcessor;
    std::map<std::string, commandFunctor>& _commandMap;

    // ============================  TMP  ============================
    /*
public:
    const std::list<std::string> &getExpressionList() const;
    std::list<std::string> &splitStringToListDelimiters(std::string str, char delimiter);
    bool isRPNExpressionValid(std::list<std::string> expressionList);
    std::list<std::string> _expressionList;
private:
    bool getNextLineToArray();
    */
};

#endif //RPN_CALCULATOR_INTERPRETER_H
