#include <gtest/gtest.h>
#include <iostream>

#include "src/common/byte_array.h"

TEST(ByteArrayTests, ShouldCreateByteArray)
{
    ByteArrayBuilder byteArrayBuilder;

    int correctNumberOfBytes = 0;
    int actualBytes = byteArrayBuilder.getNumberOfBytes();

    ASSERT_EQ(correctNumberOfBytes, actualBytes);
}