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
  correctByteArray[0] = correctValue;
  correctByteArray[1] = correctValue >> 8;
  correctByteArray[2] = correctValue >> 16;
  correctByteArray[3] = correctValue >> 24;

  for (int byteNo = 0; byteNo < 4; byteNo++)
    ASSERT_EQ(correctByteArray[byteNo], byteArray[byteNo]);

  delete correctByteArray;
}

TEST(ByteArrayTests, ShouldAddMultipleUint32ToArray)
{
  ByteArrayBuilder byteArrayBuilder;
  
  vector<uint32_t> correctValues = {20, 40, 45318294};
  int numberOfBytes = correctValues.size() * 4;

  for (auto value : correctValues)
    byteArrayBuilder.addFourByteValueToCharArray(value);

  char* byteArray = byteArrayBuilder.toArray();

  char* correctByteArray = new char[numberOfBytes];
  int byteNo = 0;

  for (auto value : correctValues) {
    correctByteArray[byteNo] = value,
    correctByteArray[byteNo + 1] = value >> 8;
    correctByteArray[byteNo + 2] = value >> 16;
    correctByteArray[byteNo + 3] = value >> 24;

    byteNo += 4;
  }

  for (int byteNo = 0; byteNo < numberOfBytes; byteNo++)
    ASSERT_EQ(correctByteArray[byteNo], byteArray[byteNo]);

  delete[] correctByteArray;
}
