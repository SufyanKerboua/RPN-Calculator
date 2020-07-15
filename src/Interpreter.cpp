//
// Created by sufyan kerboua on 14/07/2020.
//

#include "Interpreter.hpp"

Interpreter::Interpreter()
{
}

std::string Interpreter::getNextLine()
{
    std::string line;

    getline(std::cin, line);
    line = this->parseSpaceDelimiters(line);
    std::cout << line << std::endl;
    return line;
}

bool isSpace(char c) {
    return c == ' ';
}

std::string Interpreter::parseSpaceDelimiters(std::string &line)
{
    int lengthLine = line.length();

    for (int i = 0; i < lengthLine; i++) {

        while (isspace(line[i]) && isspace(line[i + 1])) {
            line.erase(i, 1);
        }
    }
    if (isspace(line[line.length() - 1])) {
        line.erase(line.length() - 1, 1);
    }

    return line;
}