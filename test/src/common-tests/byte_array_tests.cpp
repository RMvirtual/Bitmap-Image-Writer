#include <gtest/gtest.h>
#include <iostream>
#include <vector>

#include "src/common/byte_array.h"

using namespace std;

TEST(ByteArrayTests, ShouldCreateByteArray)
{
  ByteArrayBuilder byteArrayBuilder;

  int correctNumberOfBytes = 0;
  int actualBytes = byteArrayBuilder.getNumberOfBytes();

  ASSERT_EQ(correctNumberOfBytes, actualBytes);
}

TEST(ByteArrayTests, ShouldAddUint32ToArray)
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

  for (int i = 0; i < 4; i++)
    ASSERT_EQ(correctByteArray[i], byteArray[i]);

}

TEST(ByteArrayTests, ShouldAddMultipleUint32ToArray)
{
  ByteArrayBuilder byteArrayBuilder;
  
  vector<uint32_t> correctValues = {20, 40, 45318294};

  for (auto value : correctValues)
    byteArrayBuilder.addFourByteValueToCharArray(value);

  char* byteArray = byteArrayBuilder.toArray();

  char* correctByteArray = new char[12];
  int correctByteIndex = 0;

  for (auto value : correctValues) {
    correctByteArray[correctByteIndex] = value,
    correctByteArray[correctByteIndex + 1] = value >> 8;
    correctByteArray[correctByteIndex + 2] = value >> 16;
    correctByteArray[correctByteIndex + 3] = value >> 32;

    correctByteIndex += 4;
  }

  for (int i = 0; i < 12; i++)
    ASSERT_EQ(correctByteArray[i], byteArray[i]);
}
