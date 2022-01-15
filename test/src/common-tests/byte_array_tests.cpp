#include <gtest/gtest.h>
#include <vector>

#include "src/common/byte-array/byte_array_builder.h"

TEST(ByteArrayTests, ShouldAddUint8ToArray)
{
  uint8_t correctValue = 20;

  ByteArrayBuilder byteArrayBuilder;
  byteArrayBuilder.add(correctValue);
  auto byteArray = byteArrayBuilder.toByteArray();
  
  ASSERT_EQ(byteArray[0].value, correctValue);
}

TEST(ByteArrayTests, ShouldAddUint16ToArray)
{
  uint16_t correctValue = 20;
  ByteArrayBuilder byteArrayBuilder;
  byteArrayBuilder.add(correctValue);
  auto byteArray = byteArrayBuilder.toByteArray();

  int noOfBytes = byteArray.size();

  for (int byteNo = 0; byteNo < noOfBytes; byteNo++)
    ASSERT_EQ(byteArray[byteNo].value, correctValue >> (byteNo * 8));
}

TEST(ByteArrayTests, ShouldAddUint32ToArray)
{
  uint32_t correctValue = 20500;
  ByteArrayBuilder byteArrayBuilder;
  byteArrayBuilder.add(correctValue);
  auto byteArray = byteArrayBuilder.toByteArray();

  int noOfBytes = byteArray.size();

  for (int byteNo = 0; byteNo < noOfBytes; byteNo++) {
    int bitsToShift = byteNo * 8;
    uint8_t correctByte = correctValue >> bitsToShift;

    ASSERT_EQ(byteArray[byteNo].value, correctByte);
  }
}

TEST(ByteArrayTests, ShouldAddMultiple32bitUnsignedIntsToArray)
{
  std::vector<uint32_t> correctValues = {20, 40, 45318294};
  ByteArrayBuilder byteArrayBuilder;

  for (auto value : correctValues)
    byteArrayBuilder.add(value);

  auto byteArray = byteArrayBuilder.toByteArray();
  int noOfValues = correctValues.size();

  for (int valueNo = 0; valueNo < noOfValues; valueNo++) {
    auto valueBytes = byteArray.slice(valueNo * 4, (valueNo * 4) + 4);
    auto correctValue = correctValues[valueNo];

    for (int byteNo = 0; byteNo < 4; byteNo++) {
      int bitsToShift = byteNo * 8;
      uint8_t correctByte = correctValue >> bitsToShift;
      EXPECT_EQ(valueBytes[byteNo].value, correctByte);
    }
  }
}

TEST(ByteArrayTests, ShouldAddCharArrayToArray)
{
  ByteArrayBuilder byteArrayBuilder;

  unsigned char* characters = new unsigned char[3];
  characters[0] = 'a'; characters[1] = 'b'; characters[2] = 'c';

  byteArrayBuilder.add(characters, 3);
  byteArrayBuilder.add('d');

  auto bytes = byteArrayBuilder.toByteArray();

  int totalNumberOfBytes = 4;
  unsigned char* correctValues = new unsigned char[totalNumberOfBytes];
  correctValues[0] = 'a'; correctValues[1] = 'b';
  correctValues[2] = 'c'; correctValues[3] = 'd';

  for (int i = 0; i < totalNumberOfBytes; i++)
    EXPECT_EQ(correctValues[i], bytes[i].value);
}

/*

TEST(ByteArrayTests, ShouldAddMultipleSizeUnsignedIntsToArray)
{
  ByteArrayBuilder byteArrayBuilder;
  
  uint8_t correctValue8bit = 20;
  uint16_t correctValue16bit = 21596;
  uint32_t correctValue32bit = 8589429;

  byteArrayBuilder.add(correctValue16bit);
  byteArrayBuilder.add(correctValue8bit);
  byteArrayBuilder.add(correctValue32bit);

  auto byteArray = byteArrayBuilder.toByteArray();
  std::vector<unsigned char> correctValues{};

  correctValues.push_back(correctValue16bit);
  correctValues.push_back(correctValue16bit >> 8);
  correctValues.push_back(correctValue8bit);
  correctValues.push_back(correctValue32bit);
  correctValues.push_back(correctValue32bit >> 8);
  correctValues.push_back(correctValue32bit >> 16);
  correctValues.push_back(correctValue32bit >> 24);

  int numberOfBytes = correctValues.size();

  for (int byteNo = 0; byteNo < numberOfBytes; byteNo++)
    ASSERT_EQ(correctValues[byteNo], byteArray[byteNo].value);
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

  auto byteArray = byteArrayBuilder.toByteArray();
  std::vector<unsigned char> correctValues{};

  correctValues.push_back(charByte);
  correctValues.push_back(unsigned8bit);
  correctValues.push_back(unsigned16bit);
  correctValues.push_back(unsigned16bit >> 8);
  correctValues.push_back(unsigned32bit);
  correctValues.push_back(unsigned32bit >> 8);
  correctValues.push_back(unsigned32bit >> 16);
  correctValues.push_back(unsigned32bit >> 24);
  correctValues.push_back(signed8bit);
  correctValues.push_back(signed16bit);
  correctValues.push_back(signed16bit >> 8);
  correctValues.push_back(signed32bit);
  correctValues.push_back(signed32bit >> 8);
  correctValues.push_back(signed32bit >> 16);
  correctValues.push_back(signed32bit >> 24);
  correctValues.push_back(negativeSigned8bit);
  correctValues.push_back(negativeSigned16bit);
  correctValues.push_back(negativeSigned16bit >> 8);
  correctValues.push_back(negativeSigned32bit);
  correctValues.push_back(negativeSigned32bit >> 8);
  correctValues.push_back(negativeSigned32bit >> 16);
  correctValues.push_back(negativeSigned32bit >> 24);
  correctValues.push_back(normalInt);
  correctValues.push_back(normalInt >> 8);
  correctValues.push_back(normalInt >> 16);
  correctValues.push_back(normalInt >> 24);

  int correctNumberOfBytes = correctValues.size();

  for (int byteNo = 0; byteNo < correctNumberOfBytes; byteNo++)
    EXPECT_EQ(correctValues[byteNo], byteArray[byteNo].value);
}

*/