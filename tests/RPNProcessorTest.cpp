//
// Created by sufyan kerboua on 14/07/2020.
//

#include <gtest/gtest.h>
#include "RPNProcessor.hpp"

TEST(RPNProcessor_Class_Test, setInput_basic)
{
    RPNProcessor calculator;

    ASSERT_EQ(calculator.setInput(std::string("20")), true);
    ASSERT_EQ(calculator.setInput(std::string("12")), true);

    ASSERT_EQ(calculator.setInput(std::string("zaodaozidj")), false); // check basic row text
    ASSERT_EQ(calculator.setInput(std::string("")), false); // check string empty
    ASSERT_EQ(calculator.setInput(std::string("+-")), false); // check multiple operator
    ASSERT_EQ(calculator.setInput(std::string(" +")), false); // check operator with space before
    ASSERT_EQ(calculator.setInput(std::string("+ ")), false); // check operator with space after
}

TEST(RPNProcessor_Class_Test, setInput_advanced)
{
    RPNProcessor calculator;

    ASSERT_EQ(calculator.setInput(std::string("3")), true);
    ASSERT_EQ(calculator.setInput(std::string("4")), true);
    ASSERT_EQ(calculator.setInput(std::string("7")), true);
    ASSERT_EQ(calculator.setInput(std::string("+")), true);
    ASSERT_EQ(calculator.setInput(std::string("*")), true);
}

TEST(RPNProcessor_Class_Test, Mandatory_1)
{
    RPNProcessor calculator;

    ASSERT_EQ(calculator.setInput(std::string("20")), true);
    ASSERT_EQ(calculator.setInput(std::string("5")), true);
    ASSERT_EQ(calculator.setInput(std::string("/")), true);
    ASSERT_EQ(calculator.getResult(), 4);
}

TEST(RPNProcessor_Class_Test, Mandatory_2)
{
    RPNProcessor calculator;

    ASSERT_EQ(calculator.setInput(std::string("4")), true);
    ASSERT_EQ(calculator.setInput(std::string("2")), true);
    ASSERT_EQ(calculator.setInput(std::string("+")), true);
    ASSERT_EQ(calculator.setInput(std::string("3")), true);
    ASSERT_EQ(calculator.setInput(std::string("-")), true);
    ASSERT_EQ(calculator.getResult(), 3);
}

TEST(RPNProcessor_Class_Test, Mandatory_3)
{
    RPNProcessor calculator;

    ASSERT_EQ(calculator.setInput(std::string("3")), true);
    ASSERT_EQ(calculator.setInput(std::string("5")), true);
    ASSERT_EQ(calculator.setInput(std::string("8")), true);
    ASSERT_EQ(calculator.setInput(std::string("*")), true);
    ASSERT_EQ(calculator.setInput(std::string("7")), true);
    ASSERT_EQ(calculator.setInput(std::string("+")), true);
    ASSERT_EQ(calculator.setInput(std::string("*")), true);
    ASSERT_EQ(calculator.getResult(), 141);
}

TEST(RPNProcessor_Class_Test, Mandatory_4)
{
    RPNProcessor calculator;

    ASSERT_EQ(calculator.setInput(std::string("12")), true);
    ASSERT_EQ(calculator.setInput(std::string("3")), true);
    ASSERT_EQ(calculator.setInput(std::string("-")), true);
    ASSERT_EQ(calculator.setInput(std::string("3")), true);
    ASSERT_EQ(calculator.setInput(std::string("/")), true);
    ASSERT_EQ(calculator.getResult(), 3);
}

TEST(RPNProcessor_Class_Test, Mandatory_5)
{
    RPNProcessor calculator;

    ASSERT_EQ(calculator.setInput(std::string("-2")), true);
    ASSERT_EQ(calculator.setInput(std::string("3")), true);
    ASSERT_EQ(calculator.setInput(std::string("11")), true);
    ASSERT_EQ(calculator.setInput(std::string("+")), true);
    ASSERT_EQ(calculator.setInput(std::string("5")), true);
    ASSERT_EQ(calculator.setInput(std::string("-")), true);
    ASSERT_EQ(calculator.setInput(std::string("*")), true);
    ASSERT_EQ(calculator.getResult(), -18);
}

