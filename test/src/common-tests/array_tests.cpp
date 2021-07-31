#include <gtest/gtest.h>
#include <iostream>
#include "src/common/arrays.h"

using namespace Arrays;

TEST(ArrayTests, ShouldCreateArray)
{
    ArrayList<int> arrayList;
    int size = arrayList.size();
    EXPECT_EQ(1, size);
}