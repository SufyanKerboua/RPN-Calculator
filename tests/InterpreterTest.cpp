//
// Created by sufyan kerboua on 14/07/2020.
//

#include <iostream>
#include <gtest/gtest.h>
#include "Interpreter.cpp"

class Interpreter_test : public Interpreter {
public:
    std::string parseSpaceDelimiters(std::string line) {
        return Interpreter::parseSpaceDelimiters(line);
    }
};

TEST(InterpreterTest, MethodCheck)
{
    Interpreter_test inter;
    ASSERT_EQ(inter.parseSpaceDelimiters(std::string("salut gars   a b c    ")), std::string("salut gars a b c"));
    ASSERT_EQ(inter.parseSpaceDelimiters(std::string("salut gars   a  a  a")), std::string("salut gars a a a"));
    ASSERT_EQ(inter.parseSpaceDelimiters(std::string("salut gars   a a a")), std::string("salut gars a a a"));
    ASSERT_EQ(inter.parseSpaceDelimiters(std::string("salut     gars   a       a a")), std::string("salut gars a a a"));
    ASSERT_EQ(inter.parseSpaceDelimiters(std::string("       salut     gars   a a                       a")), std::string(" salut gars a a a"));
}
