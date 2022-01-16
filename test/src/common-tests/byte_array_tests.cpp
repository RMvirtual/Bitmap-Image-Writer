#include <gtest/gtest.h>
#include <vector>

#include "src/common/byte-array/byte_array.h"

void addValueToVector(std::vector<unsigned char>& vector, int32_t value)
{
  for (int byteNo = 0; byteNo < 4; byteNo++)
    vector.push_back(value >> (byteNo * 8));
}

void addValueToVector(std::vector<unsigned char>& vector, int16_t value)
{
  for (int byteNo = 0; byteNo < 2; byteNo++)
    vector.push_back(value >> (byteNo * 8));
}

void addValueToVector(std::vector<unsigned char>& vector, uint32_t value)
{
  for (int byteNo = 0; byteNo < 4; byteNo++)
    vector.push_back(value >> (byteNo * 8));
}

void addValueToVector(std::vector<unsigned char>& vector, uint16_t value)
{
  for (int byteNo = 0; byteNo < 2; byteNo++)
    vector.push_back(value >> (byteNo * 8));
}

ByteArray getEverySizeByteArray()
{
  ByteArray byteArray;

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

  byteArray.add(charByte);
  byteArray.add(unsigned8bit);
  byteArray.add(unsigned16bit);
  byteArray.add(unsigned32bit);
  byteArray.add(signed8bit);
  byteArray.add(signed16bit);
  byteArray.add(signed32bit);
  byteArray.add(negativeSigned8bit);
  byteArray.add(negativeSigned16bit);
  byteArray.add(negativeSigned32bit);
  byteArray.add(normalInt);

  return byteArray;
}

std::vector<unsigned char> getEverySizeCorrectValues()
{
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
  
  std::vector<unsigned char> correctValues{};
  
  correctValues.push_back(charByte);
  correctValues.push_back(unsigned8bit);
  addValueToVector(correctValues, unsigned16bit);
  addValueToVector(correctValues, unsigned32bit);
  correctValues.push_back(signed8bit);
  addValueToVector(correctValues, signed16bit);
  addValueToVector(correctValues, signed32bit);
  correctValues.push_back(negativeSigned8bit);
  addValueToVector(correctValues, negativeSigned16bit);
  addValueToVector(correctValues, negativeSigned32bit);
  addValueToVector(correctValues, normalInt);

  return correctValues;
}

TEST(ByteArrayTests, ShouldAddUint8ToArray)
{
  uint8_t correctValue = 20;

  ByteArray byteArray;
  byteArray.add(correctValue);
  
  ASSERT_EQ(byteArray[0].value, correctValue);
}

TEST(ByteArrayTests, ShouldAddUint16ToArray)
{
  uint16_t correctValue = 20;

  ByteArray byteArray;
  byteArray.add(correctValue);
  int noOfBytes = byteArray.size();

  for (int byteNo = 0; byteNo < noOfBytes; byteNo++)
    ASSERT_EQ(byteArray[byteNo].value, correctValue >> (byteNo * 8));
}

TEST(ByteArrayTests, ShouldAddUint32ToArray)
{
  uint32_t correctValue = 20500;
  
  ByteArray byteArray;
  byteArray.add(correctValue);
  int noOfBytes = byteArray.size();

  for (int byteNo = 0; byteNo < noOfBytes; byteNo++) {
    int bitsToShift = byteNo * 8;
    uint8_t correctByte = correctValue >> bitsToShift;

    ASSERT_EQ(byteArray[byteNo].value, correctByte);
  }
}

TEST(ByteArrayTests, ShouldAddMultiple32bitUnsignedIntsToArray)
{
  ByteArray byteArray;
  std::vector<unsigned char> correctValues;
  std::vector<uint32_t> values = {20, 40, 45318294};

  for (auto value : values) {
    byteArray.add(value);
    addValueToVector(correctValues, value);
  }

  int noOfValues = correctValues.size();

  for (int byteNo = 0; byteNo < noOfValues; byteNo++)
    EXPECT_EQ(byteArray[byteNo].value, correctValues[byteNo]);
}

TEST(ByteArrayTests, ShouldAddCharArrayToArray)
{
  int noOfBytes = 4;
  unsigned char* correctValues = new unsigned char[noOfBytes];
  correctValues[0] = 'a';
  correctValues[1] = 'b';
  correctValues[2] = 'c';
  correctValues[3] = 'd';

  ByteArray byteArray;
  byteArray.add(correctValues, noOfBytes);

  for (int byteNo = 0; byteNo < noOfBytes; byteNo++)
    EXPECT_EQ(correctValues[byteNo], byteArray[byteNo].value);
}

TEST(ByteArrayTests, ShouldAddMultipleSizeUnsignedIntsToArray)
{
  ByteArray byteArray;
  
  uint8_t value8Bit = 20;
  uint16_t value16Bit = 21596;
  uint32_t value32Bit = 8589429;

  byteArray.add(value8Bit);
  byteArray.add(value16Bit);
  byteArray.add(value32Bit);

  std::vector<unsigned char> correctValues{};
  correctValues.push_back(value8Bit);
  addValueToVector(correctValues, value16Bit);
  addValueToVector(correctValues, value32Bit);

  int numberOfBytes = correctValues.size();

  for (int byteNo = 0; byteNo < numberOfBytes; byteNo++)
    EXPECT_EQ(correctValues[byteNo], byteArray[byteNo].value);
}

TEST(ByteArrayTests, ShouldAddEverySizeIntToBitmapBuilder)
{
  auto byteArray = getEverySizeByteArray();
  std::vector<unsigned char> correctValues = getEverySizeCorrectValues();
 
  int correctNumberOfBytes = correctValues.size();

  for (int byteNo = 0; byteNo < correctNumberOfBytes; byteNo++)
    EXPECT_EQ(correctValues[byteNo], byteArray[byteNo].value);
}