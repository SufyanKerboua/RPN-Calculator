//
// Created by sufyan kerboua on 14/07/2020.
//

#include <gtest/gtest.h>
#include "Tools.hpp"

TEST(Tools_Class_Test, isOperandOrOperator)
{
    Tools tool;

    // Operand
    ASSERT_EQ(tool.isOperandOrOperator(std::string("1234")), true);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("-1234")), true);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("12.34")), true);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("-14.34")), true);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("-0")), true);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("0")), true);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("012")), true);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("-012")), true);

    ASSERT_EQ(tool.isOperandOrOperator(std::string("|")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string(":-!")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("test")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("12.34b456")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("-12.34b456")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("--3")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("15.")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("-15.")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("43,9")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("-43,9")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("15..0")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("-15..0")), false);

    //Operator
    ASSERT_EQ(tool.isOperandOrOperator(std::string("+")), true);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("-")), true);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("/")), true);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("*")), true);

    ASSERT_EQ(tool.isOperandOrOperator(std::string(":-!")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("%")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("+-")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("/+")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("o-")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("+ ")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("a")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("erty")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string(" ")), false);
    ASSERT_EQ(tool.isOperandOrOperator(std::string("")), false);
}

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

    ASSERT_EQ(tool.isOperand(std::string("+")), false);
    ASSERT_EQ(tool.isOperand(std::string("-")), false);
    ASSERT_EQ(tool.isOperand(std::string("*")), false);
    ASSERT_EQ(tool.isOperand(std::string("/")), false);
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

TEST(Tools_Class_Test, removeUnnecessarySpace)
{
    Tools tool;
    std::string str("salut gars   a b c    ");

    ASSERT_EQ(tool.removeUnnecessarySpace(str), std::string("salut gars a b c"));

    str = std::string("salut gars   a  a  a");
    ASSERT_EQ(tool.removeUnnecessarySpace(str), std::string("salut gars a a a"));

    str = std::string("salut gars   a a a");
    ASSERT_EQ(tool.removeUnnecessarySpace(str), std::string("salut gars a a a"));

    str = std::string("salut     gars   a       a a");
    ASSERT_EQ(tool.removeUnnecessarySpace(str), std::string("salut gars a a a"));

    str = std::string("       salut     gars   a a                       a");
    ASSERT_EQ(tool.removeUnnecessarySpace(str), std::string("salut gars a a a"));
}


TEST(Tools_Class_Test, Set_Get_ErrorToken) {
    Tools tool;

    tool.setErrorToken(Tools::errorEnum::Success);
    ASSERT_EQ(tool.getErrorToken(), std::string("none"));

    tool.setErrorToken(Tools::errorEnum::BadSyntax);
    ASSERT_EQ(tool.getErrorToken(), std::string("bad_syntax"));

    tool.setErrorToken(Tools::errorEnum::MissingOperand);
    ASSERT_EQ(tool.getErrorToken(), std::string("missing_operand"));

    tool.setErrorToken(Tools::errorEnum::DivisionByZero);
    ASSERT_EQ(tool.getErrorToken(), std::string("division_by_zero"));
}