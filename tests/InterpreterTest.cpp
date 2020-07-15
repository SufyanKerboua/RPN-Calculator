//
// Created by sufyan kerboua on 14/07/2020.
//

#include <iostream>
#include <gtest/gtest.h>
#include "Tools.cpp"
#include "Interpreter.cpp"

class InterpreterTest : public Interpreter {
public:
    std::string removeUnnecessarySpace(std::string line) {
        return Interpreter::removeUnnecessarySpace(line);
    }
};

TEST(Interpreter_Class_Test, removeUnnecessarySpace)
{
    InterpreterTest inter;

    ASSERT_EQ(inter.removeUnnecessarySpace(std::string("salut gars   a b c    ")), std::string("salut gars a b c"));
    ASSERT_EQ(inter.removeUnnecessarySpace(std::string("salut gars   a  a  a")), std::string("salut gars a a a"));
    ASSERT_EQ(inter.removeUnnecessarySpace(std::string("salut gars   a a a")), std::string("salut gars a a a"));
    ASSERT_EQ(inter.removeUnnecessarySpace(std::string("salut     gars   a       a a")), std::string("salut gars a a a"));
    ASSERT_EQ(inter.removeUnnecessarySpace(std::string("       salut     gars   a a                       a")), std::string("salut gars a a a"));
}