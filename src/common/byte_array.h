#ifndef BYTE_ARRAY_H
#define BYTE_ARRAY_H

#include <cstdint>
#include <vector>

class ByteArrayBuilder
{
public:
  ByteArrayBuilder();

  // Add a character (converted to an 8-bit unsigned integer).
  void addValue(char value);

  // Adds a value of 1 byte.
  void addValue(uint8_t value);

  // Adds a value of 1 byte.
  void addValue(int8_t value);

  // Adds a value of 2 bytes.
  void addValue(uint16_t value);

  // Adds a value of 2 bytes.
  void addValue(int16_t value);

  // Adds a value of 4 bytes.
  void addValue(uint32_t value);

  // Adds a value of 4 bytes.
  void addValue(int32_t value);

  /**
   * Returns a character array pointer towards a copy of the bytes
   * constructed from adding to the ByteArrayBuilder class.
   */ 
  char* toBytes();
  
  /**
   * Returns the current number of bytes that the length of the
   * Byte Array currently stands at.
   */
  int getNumberOfBytes();

private:
  std::vector<char> byteVector;
  int numberOfBytes;

  /**
   * Converts the underlying vector of bytes into a new char array area
   * of dynamic memory and returns a pointer to it.
   */
  char* copyArray();
  char* getEmptyArray(int sizeInBytes);
  void copyVectorToArray(char* destinationArray);
  void convertValueToBytes(uint8_t value);
  void convertValueToBytes(int8_t value);
  void convertValueToBytes(uint16_t value);
  void convertValueToBytes(int16_t value);
  void convertValueToBytes(uint32_t value);
  void convertValueToBytes(int32_t value);
  int rightBitShiftValue(int value, int numberOfBits);
};

#endif