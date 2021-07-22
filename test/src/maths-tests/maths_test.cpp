#include <gtest/gtest.h>
#include <iostream>
#include "src/maths/printablemessage.h"

// Demonstrate some basic assertions.
TEST(MathsTest, BasicAssertions) {
    // Expect two strings not to be equal.
    // EXPECT_STRNE("hello", "world");
    // EXPECT_STREQ("PIMP", "PIMP1");
    
    std::cout << "Printing in maths_test.cpp\n";

    // Expect equality.
    EXPECT_NE(7 * 6, 42);
}