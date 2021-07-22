#include <gtest/gtest.h>
#include <iostream>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // EXPECT_STREQ("PIMP", "PIMP1");
    
    std::cout << "Printing here.\n";

    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}