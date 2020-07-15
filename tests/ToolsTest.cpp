//
// Created by sufyan kerboua on 14/07/2020.
//

#include <gtest/gtest.h>
#include "Tools.hpp"

class ToolsTest : public Tools {
public:
    bool isOperand(std::string operand) {
        return Tools::isOperand(operand);
    }

    bool isOperator(std::string op) {
        return Tools::isOperator(op);
    }
};

TEST(Tools_Class_Test, isOperator)
{
    Tools tool;

    ASSERT_EQ(tool.isOperator(std::string("+")), true);
    ASSERT_EQ(tool.isOperator(std::string("-")), true);
    ASSERT_EQ(tool.isOperator(std::string("/")), true);
    ASSERT_EQ(tool.isOperator(std::string("*")), true);

    ASSERT_EQ(tool.isOperator(std::string(":-!")), false);
    ASSERT_EQ(tool.isOperator(std::string("%")), false);
    ASSERT_EQ(tool.isOperator(std::string("+-")), false);
    ASSERT_EQ(tool.isOperator(std::string("/+")), false);
    ASSERT_EQ(tool.isOperator(std::string("o-")), false);
    ASSERT_EQ(tool.isOperator(std::string("+ ")), false);
    ASSERT_EQ(tool.isOperator(std::string("a")), false);
    ASSERT_EQ(tool.isOperator(std::string("erty")), false);
    ASSERT_EQ(tool.isOperator(std::string("0")), false);
    ASSERT_EQ(tool.isOperator(std::string("34567")), false);
    ASSERT_EQ(tool.isOperator(std::string(" ")), false);
    ASSERT_EQ(tool.isOperator(std::string("")), false);
}


TEST(Tools_Class_Test, isOperand)
{
    Tools tool;

    ASSERT_EQ(tool.isOperand(std::string("1234")), true);
    ASSERT_EQ(tool.isOperand(std::string("-1234")), true);
    ASSERT_EQ(tool.isOperand(std::string("12.34")), true);
    ASSERT_EQ(tool.isOperand(std::string("-14.34")), true);
    ASSERT_EQ(tool.isOperand(std::string("-0")), true);
    ASSERT_EQ(tool.isOperand(std::string("0")), true);
    ASSERT_EQ(tool.isOperand(std::string("012")), true);
    ASSERT_EQ(tool.isOperand(std::string("-012")), true);

    ASSERT_EQ(tool.isOperand(std::string("|")), false);
    ASSERT_EQ(tool.isOperand(std::string(":-!")), false);
    ASSERT_EQ(tool.isOperand(std::string("test")), false);
    ASSERT_EQ(tool.isOperand(std::string("12.34b456")), false);
    ASSERT_EQ(tool.isOperand(std::string("-12.34b456")), false);
    ASSERT_EQ(tool.isOperand(std::string("--3")), false);
    ASSERT_EQ(tool.isOperand(std::string("15.")), false);
    ASSERT_EQ(tool.isOperand(std::string("-15.")), false);
    ASSERT_EQ(tool.isOperand(std::string("43,9")), false);
    ASSERT_EQ(tool.isOperand(std::string("-43,9")), false);
    ASSERT_EQ(tool.isOperand(std::string("15..0")), false);
    ASSERT_EQ(tool.isOperand(std::string("-15..0")), false);
}
