#include <gtest/gtest.h>
#include <iostream>
#include "src/maths/vector/vector.h"

using namespace Vectorable;

// Demonstrate some basic assertions.
TEST(MathsTest, BasicAssertions) {
    // Expect two strings not to be equal.
    // EXPECT_STRNE("hello", "world");
    // EXPECT_STREQ("PIMP", "PIMP1");
    
    std::cout << "Printing in maths_test.cpp\n";

    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

TEST(MathsTest, LengthShouldBeFive)
{
    Vector vector = Vector();
    int length = vector.length();

    EXPECT_EQ(5, length);
}