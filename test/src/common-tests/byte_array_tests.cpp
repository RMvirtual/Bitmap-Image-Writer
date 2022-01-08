#include <gtest/gtest.h>
#include <iostream>
#include <vector>

#include "src/common/byte_array_builder.h"

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

  byteArrayBuilder.add(correctValue);

  unsigned char* byteArray = byteArrayBuilder.toBytes();
  char* correctByteArray = new char[1];
  correctByteArray[0] = correctValue;

  ASSERT_EQ(correctByteArray[0], byteArray[0]);

  delete[] byteArray;
  delete[] correctByteArray;
}

TEST(ByteArrayTests, ShouldAddUint16ToArray)
{
  ByteArrayBuilder byteArrayBuilder;
  std::vector<uint16_t> values = {20};

  for (auto value : values)
    byteArrayBuilder.add(value);

  unsigned char* byteArray = byteArrayBuilder.toBytes();
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

  byteArrayBuilder.add(correctValue);

  unsigned char* byteArray = byteArrayBuilder.toBytes();

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

TEST(ByteArrayTests, ShouldAddMultiple32bitUnsignedIntsToArray)
{
  ByteArrayBuilder byteArrayBuilder;
  
  std::vector<uint32_t> correctValues = {20, 40, 45318294};

  for (auto value : correctValues)
    byteArrayBuilder.add(value);

  unsigned char* byteArray = byteArrayBuilder.toBytes();

  int numberOfBytes = correctValues.size() * 4;
  unsigned char* correctByteArray = new unsigned char[numberOfBytes];
  int byteNo = 0;

  for (auto value : correctValues) {
    correctByteArray[byteNo] = value;
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

TEST(ByteArrayTests, ShouldAddCharacterArrayToBuilder)
{
  ByteArrayBuilder byteArrayBuilder;

  unsigned char* characters = new unsigned char[3];
  characters[0] = 'a'; characters[1] = 'b'; characters[2] = 'c';

  byteArrayBuilder.add(characters, 3);
  byteArrayBuilder.add('d');

  unsigned char* bytes = byteArrayBuilder.toBytes();

  int totalNumberOfBytes = 4;
  unsigned char* correctValues = new unsigned char[totalNumberOfBytes];
  correctValues[0] = 'a'; correctValues[1] = 'b';
  correctValues[2] = 'c'; correctValues[3] = 'd';

  for (int i = 0; i < totalNumberOfBytes; i++)
    EXPECT_EQ(correctValues[i], bytes[i]);
}

TEST(ByteArrayTests, ShouldAddMultipleSizeUnsignedIntsToArray)
{
  ByteArrayBuilder byteArrayBuilder;
  
  uint8_t correctValue8bit = 20;
  uint16_t correctValue16bit = 21596;
  uint32_t correctValue32bit = 8589429;

  byteArrayBuilder.add(correctValue16bit);
  byteArrayBuilder.add(correctValue8bit);
  byteArrayBuilder.add(correctValue32bit);

  unsigned char* byteArray = byteArrayBuilder.toBytes();

  int numberOfBytes = 7;
  unsigned char* correctByteArray = new unsigned char[numberOfBytes];
  int byteNo = 0;

  correctByteArray[0] = correctValue16bit;
  correctByteArray[1] = correctValue16bit >> 8;
  correctByteArray[2] = correctValue8bit;
  correctByteArray[3] = correctValue32bit;
  correctByteArray[4] = correctValue32bit >> 8;
  correctByteArray[5] = correctValue32bit >> 16;
  correctByteArray[6] = correctValue32bit >> 24;

  for (int byteNo = 0; byteNo < numberOfBytes; byteNo++)
    ASSERT_EQ(correctByteArray[byteNo], byteArray[byteNo]);

  delete[] byteArray;
  delete[] correctByteArray;
}

TEST(ByteArrayTests, ShouldAddEverySizeIntToBitmapBuilder)
{
  ByteArrayBuilder byteArrayBuilder;

  char charByte = 'a';
  uint8_t unsigned8bit = 20;
  uint16_t unsigned16bit = 21596;
  uint32_t unsigned32bit = 8589429;
  int8_t signed8bit = 425;
  int16_t signed16bit = 529;
  int32_t signed32bit = 51891897;
  int8_t negativeSigned8bit = -425;
  int16_t negativeSigned16bit = -529;
  int32_t negativeSigned32bit = -51891897;
  int normalInt = 44;
  int normalNegativeInt = -44;

  byteArrayBuilder.add(charByte);
  byteArrayBuilder.add(unsigned8bit);
  byteArrayBuilder.add(unsigned16bit);
  byteArrayBuilder.add(unsigned32bit);
  byteArrayBuilder.add(signed8bit);
  byteArrayBuilder.add(signed16bit);
  byteArrayBuilder.add(signed32bit);
  byteArrayBuilder.add(negativeSigned8bit);
  byteArrayBuilder.add(negativeSigned16bit);
  byteArrayBuilder.add(negativeSigned32bit);
  byteArrayBuilder.add(normalInt);

  unsigned char* byteArray = byteArrayBuilder.toBytes();

  int correctNumberOfBytes = 26;
  unsigned char* correctByteArray = new unsigned char[correctNumberOfBytes];
  int byteNo = 0;

  correctByteArray[0] = charByte;
  correctByteArray[1] = unsigned8bit;
  correctByteArray[2] = unsigned16bit;
  correctByteArray[3] = unsigned16bit >> 8;
  correctByteArray[4] = unsigned32bit;
  correctByteArray[5] = unsigned32bit >> 8;
  correctByteArray[6] = unsigned32bit >> 16;
  correctByteArray[7] = unsigned32bit >> 24;
  correctByteArray[8] = signed8bit;
  correctByteArray[9] = signed16bit;
  correctByteArray[10] = signed16bit >> 8;
  correctByteArray[11] = signed32bit;
  correctByteArray[12] = signed32bit >> 8;
  correctByteArray[13] = signed32bit >> 16;
  correctByteArray[14] = signed32bit >> 24;
  correctByteArray[15] = negativeSigned8bit;
  correctByteArray[16] = negativeSigned16bit;
  correctByteArray[17] = negativeSigned16bit >> 8;
  correctByteArray[18] = negativeSigned32bit;
  correctByteArray[19] = negativeSigned32bit >> 8;
  correctByteArray[20] = negativeSigned32bit >> 16;
  correctByteArray[21] = negativeSigned32bit >> 24;
  correctByteArray[22] = normalInt;
  correctByteArray[23] = normalInt >> 8;
  correctByteArray[24] = normalInt >> 16;
  correctByteArray[25] = normalInt >> 24;

  for (int byteNo = 0; byteNo < correctNumberOfBytes; byteNo++)
    EXPECT_EQ(correctByteArray[byteNo], byteArray[byteNo]);
    
  delete[] byteArray;
  delete[] correctByteArray;
}