//
// Created by sufyan kerboua on 14/07/2020.
//
/*

#include <iostream>
#include <gtest/gtest.h>
#include "Interpreter.cpp"
#include "Tools.cpp"
#include "RPNProcessor.cpp"

using commandFunctor = std::function<void(void)>;

std::map<std::string, std::function<void(void)>> COMMANDS;

class InterpreterTest : public Interpreter {
public:
    explicit InterpreterTest(std::map<std::string, commandFunctor>& commandMap);

    std::string removeUnnecessarySpace(std::string line) {
        return Interpreter::removeUnnecessarySpace(line);
    }
};

TEST(Interpreter_Class_Test, removeUnnecessarySpace)
{
    InterpreterTest inter(COMMANDS);

    ASSERT_EQ(inter.removeUnnecessarySpace(std::string("salut gars   a b c    ")), std::string("salut gars a b c"));
    ASSERT_EQ(inter.removeUnnecessarySpace(std::string("salut gars   a  a  a")), std::string("salut gars a a a"));
    ASSERT_EQ(inter.removeUnnecessarySpace(std::string("salut gars   a a a")), std::string("salut gars a a a"));
    ASSERT_EQ(inter.removeUnnecessarySpace(std::string("salut     gars   a       a a")), std::string("salut gars a a a"));
    ASSERT_EQ(inter.removeUnnecessarySpace(std::string("       salut     gars   a a                       a")), std::string("salut gars a a a"));
}

  */
