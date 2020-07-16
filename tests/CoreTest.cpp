//
// Created by sufyan kerboua on 14/07/2020.
//

#include <gtest/gtest.h>
#include "Core.hpp"

class CoreTest : public Core {
public:
    bool isCommand(const std::string &line) {
        return Core::isCommand(line);
    }
};

TEST(Core_Class_Test, isCommand)
{
    CoreTest core;

    ASSERT_EQ(core.isCommand(std::string("clear")), true);
    ASSERT_EQ(core.isCommand(std::string("quit")), true);
    ASSERT_EQ(core.isCommand(std::string("help")), true);

    ASSERT_EQ(core.isCommand(std::string("   quit")), false);
    ASSERT_EQ(core.isCommand(std::string("clear      ")), false);
    ASSERT_EQ(core.isCommand(std::string(" clear")), false);
    ASSERT_EQ(core.isCommand(std::string(" clear ")), false);
    ASSERT_EQ(core.isCommand(std::string("clear ")), false);
    ASSERT_EQ(core.isCommand(std::string("")), false);
    ASSERT_EQ(core.isCommand(std::string("a")), false);
    ASSERT_EQ(core.isCommand(std::string("Clear")), false);
    ASSERT_EQ(core.isCommand(std::string("clea r")), false);
    ASSERT_EQ(core.isCommand(std::string(" cl ear")), false);
    ASSERT_EQ(core.isCommand(std::string(" cl ear ")), false);
    ASSERT_EQ(core.isCommand(std::string("aclear")), false);
}
