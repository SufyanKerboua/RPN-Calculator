//
// Created by sufyan kerboua on 14/07/2020.
//

#include <gtest/gtest.h>
#include "RPNProcessor.hpp"

TEST(RPNProcessor_Class_Test, setInput_basic)
{
    RPNProcessor calculator;

    ASSERT_EQ(calculator.setInput(std::string("20")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("12")), Tools::errorEnum::Success);

    ASSERT_EQ(calculator.setInput(std::string("zaodaozidj")), Tools::errorEnum::BadSyntax); // check basic row text
    ASSERT_EQ(calculator.setInput(std::string("")), Tools::errorEnum::BadSyntax); // check string empty
    ASSERT_EQ(calculator.setInput(std::string("+-")), Tools::errorEnum::BadSyntax); // check multiple operator
    ASSERT_EQ(calculator.setInput(std::string(" +")), Tools::errorEnum::BadSyntax); // check operator with space before
    ASSERT_EQ(calculator.setInput(std::string("+ ")), Tools::errorEnum::BadSyntax); // check operator with space after
}

TEST(RPNProcessor_Class_Test, setInput_advanced)
{
    RPNProcessor calculator;

    ASSERT_EQ(calculator.setInput(std::string("3")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("4")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("7")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("+")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("*")), Tools::errorEnum::Success);
}

TEST(RPNProcessor_Class_Test, divideByZero_basic) {
    RPNProcessor calculator;

    ASSERT_EQ(calculator.setInput(std::string("20")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("0")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("/")), Tools::errorEnum::DivisionByZero);
}

TEST(RPNProcessor_Class_Test, divideByZero_advanced) {
    RPNProcessor calculator;

    ASSERT_EQ(calculator.setInput(std::string("20")), Tools::errorEnum::Success);

    ASSERT_EQ(calculator.setInput(std::string("5")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("-5")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("+")), Tools::errorEnum::Success);

    ASSERT_EQ(calculator.setInput(std::string("/")), Tools::errorEnum::DivisionByZero);
}

TEST(RPNProcessor_Class_Test, Mandatory_1)
{
    RPNProcessor calculator;

    ASSERT_EQ(calculator.setInput(std::string("20")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("5")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("/")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.getResult(), 4);
}

TEST(RPNProcessor_Class_Test, Mandatory_2)
{
    RPNProcessor calculator;

    ASSERT_EQ(calculator.setInput(std::string("4")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("2")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("+")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("3")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("-")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.getResult(), 3);
}

TEST(RPNProcessor_Class_Test, Mandatory_3)
{
    RPNProcessor calculator;

    ASSERT_EQ(calculator.setInput(std::string("3")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("5")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("8")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("*")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("7")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("+")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("*")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.getResult(), 141);
}

TEST(RPNProcessor_Class_Test, Mandatory_4)
{
    RPNProcessor calculator;

    ASSERT_EQ(calculator.setInput(std::string("12")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("3")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("-")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("3")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("/")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.getResult(), 3);
}

TEST(RPNProcessor_Class_Test, Mandatory_5)
{
    RPNProcessor calculator;

    ASSERT_EQ(calculator.setInput(std::string("-2")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("3")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("11")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("+")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("5")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("-")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.setInput(std::string("*")), Tools::errorEnum::Success);
    ASSERT_EQ(calculator.getResult(), -18);
}

