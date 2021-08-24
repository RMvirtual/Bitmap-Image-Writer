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

TEST(ByteArrayTests, ShouldAddByteToArray)
{
  ByteArrayBuilder byteArrayBuilder;
  uint32_t correctValue = 20;

  byteArrayBuilder.addFourByteValueToCharArray(correctValue);
  char* byteArray = byteArrayBuilder.toArray();

  char* correctByteArray = new char[4];
  correctByteArray[0] = correctValue,
  correctByteArray[1] = correctValue >> 8;
  correctByteArray[2] = correctValue >> 16;
  correctByteArray[3] = correctValue >> 32;

  for (int i = 0; i < 4; i++) {
    ASSERT_EQ(correctByteArray[i], byteArray[i]);
  }

}