#ifndef BYTE_ARRAY_H
#define BYTE_ARRAY_H

#include <cstdint>

class ByteArrayBuilder
{
public:
  ByteArrayBuilder();
  ~ByteArrayBuilder();
  void addTwoByteValueToCharArray(uint16_t value);
  void addFourByteValueToCharArray(uint32_t value);
  void overwriteTwoByteValueInCharArray(int startingIndex, uint16_t value);
  void overwriteFourByteValueInCharArray(int startingIndex, uint32_t value);
  char* toArray();
  int getNumberOfBytes();

private:
  char* byteArray;
  int numberOfBytes;
};

#endif