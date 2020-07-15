//
// Created by sufyan kerboua on 14/07/2020.
//

#include <gtest/gtest.h>
#include "Core.cpp"

class CoreTest : public Core {
public:
    int coreTest() {
        return Core::coreTest();
    }
};

TEST(CoreTest, MethodCheck1)
{
    CoreTest core;
    ASSERT_EQ(core.coreTest(), 12);
}

TEST(CoreTest, MethodCheck)
{
    CoreTest core;
    ASSERT_GT(core.coreTest(), 10);
}
