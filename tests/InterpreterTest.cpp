//
// Created by sufyan kerboua on 14/07/2020.
//

#include <iostream>
#include <gtest/gtest.h>
#include "Interpreter.cpp"
#include "Tools.cpp"
#include "RPNProcessor.cpp"

std::map<std::string, std::function<void(void)>> COMMAND;

TEST(Interpreter_Class_Test, isCommand)
{
    Interpreter inter(COMMAND);

    ASSERT_EQ(inter.isCommand(std::string("clear")), true);
    ASSERT_EQ(inter.isCommand(std::string("quit")), true);
    ASSERT_EQ(inter.isCommand(std::string("help")), true);

    ASSERT_EQ(inter.isCommand(std::string("   quit")), false);
    ASSERT_EQ(inter.isCommand(std::string("clear      ")), false);
    ASSERT_EQ(inter.isCommand(std::string(" clear")), false);
    ASSERT_EQ(inter.isCommand(std::string(" clear ")), false);
    ASSERT_EQ(inter.isCommand(std::string("clear ")), false);
    ASSERT_EQ(inter.isCommand(std::string("")), false);
    ASSERT_EQ(inter.isCommand(std::string("a")), false);
    ASSERT_EQ(inter.isCommand(std::string("Clear")), false);
    ASSERT_EQ(inter.isCommand(std::string("clea r")), false);
    ASSERT_EQ(inter.isCommand(std::string(" cl ear")), false);
    ASSERT_EQ(inter.isCommand(std::string(" cl ear ")), false);
    ASSERT_EQ(inter.isCommand(std::string("aclear")), false);
}
