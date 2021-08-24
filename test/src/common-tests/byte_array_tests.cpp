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

TEST(ByteArrayTests, ShouldAddUint8ToArray)
{
  ByteArrayBuilder byteArrayBuilder;
  uint8_t correctValue = 20;

  byteArrayBuilder.addValue(correctValue);

  char* byteArray = byteArrayBuilder.toArray();
  char* correctByteArray = new char[1];
  correctByteArray[0] = correctValue;

  ASSERT_EQ(correctByteArray[0], byteArray[0]);

  delete[] byteArray;
  delete[] correctByteArray;
}

TEST(ByteArrayTests, ShouldAddUint16ToArray)
{
  ByteArrayBuilder byteArrayBuilder;
  vector<uint16_t> values = {20};

  for (auto value : values)
    byteArrayBuilder.addValue(value);

  char* byteArray = byteArrayBuilder.toArray();
  int numberOfBytes = byteArrayBuilder.getNumberOfBytes();

  char* correctByteArray = new char[2];
  correctByteArray[0] = values[0];
  correctByteArray[1] = values[0] >> 8;

  for (int byteNo = 0; byteNo < 2; byteNo++)
    ASSERT_EQ(correctByteArray[byteNo], byteArray[byteNo]);

  delete[] byteArray;
  delete[] correctByteArray;
}

TEST(ByteArrayTests, ShouldAddUint32ToArray)
{
  ByteArrayBuilder byteArrayBuilder;
  uint32_t correctValue = 20;

  byteArrayBuilder.addValue(correctValue);

  char* byteArray = byteArrayBuilder.toArray();

  char* correctByteArray = new char[4];
  correctByteArray[0] = correctValue;
  correctByteArray[1] = correctValue >> 8;
  correctByteArray[2] = correctValue >> 16;
  correctByteArray[3] = correctValue >> 24;

  for (int byteNo = 0; byteNo < 4; byteNo++)
    ASSERT_EQ(correctByteArray[byteNo], byteArray[byteNo]);

  delete[] byteArray;
  delete[] correctByteArray;
}

TEST(ByteArrayTests, ShouldAddMultipleUint32ToArray)
{
  ByteArrayBuilder byteArrayBuilder;
  
  vector<uint32_t> correctValues = {20, 40, 45318294};

  for (auto value : correctValues)
    byteArrayBuilder.addValue(value);

  char* byteArray = byteArrayBuilder.toArray();

  int numberOfBytes = correctValues.size() * 4;
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

  delete[] byteArray;
  delete[] correctByteArray;
}
