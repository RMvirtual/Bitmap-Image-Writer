#include <gtest/gtest.h>
#include <iostream>

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

  for (int i = 0; i < 4; i++) {
    ASSERT_EQ(correctByteArray[i], byteArray[i]);
  }
}

TEST(ByteArrayTests, ShouldAddMultipleUint32ToArray)
{
  ByteArrayBuilder byteArrayBuilder;
  uint32_t correctValue1 = 20;
  uint32_t correctValue2 = 40;
  uint32_t correctValue3 = 45318294;

  byteArrayBuilder.addFourByteValueToCharArray(correctValue1);
  byteArrayBuilder.addFourByteValueToCharArray(correctValue2);
  byteArrayBuilder.addFourByteValueToCharArray(correctValue3);

  char* byteArray = byteArrayBuilder.toArray();

  char* correctByteArray = new char[12];
  correctByteArray[0] = correctValue1,
  correctByteArray[1] = correctValue1 >> 8;
  correctByteArray[2] = correctValue1 >> 16;
  correctByteArray[3] = correctValue1 >> 32;
  correctByteArray[4] = correctValue2,
  correctByteArray[5] = correctValue2 >> 8;
  correctByteArray[6] = correctValue2 >> 16;
  correctByteArray[7] = correctValue2 >> 32;
  correctByteArray[8] = correctValue3,
  correctByteArray[9] = correctValue3 >> 8;
  correctByteArray[10] = correctValue3 >> 16;
  correctByteArray[11] = correctValue3 >> 32;

  for (int i = 0; i < 12; i++)
    ASSERT_EQ(correctByteArray[i], byteArray[i]);
}
