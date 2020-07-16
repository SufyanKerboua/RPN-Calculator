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

TEST(Core_Class_Test, MethodCheck1)
{
    CoreTest core;
    ASSERT_EQ(core.coreTest(), 12);
}
