#ifndef BYTE_ARRAY_BUILDER_H
#define BYTE_ARRAY_BUILDER_H

#include <cstdint>
#include <string>
#include <vector>

#include "src/common/byte-array/byte.h"
#include "src/common/byte-array/byte_array.h"

class ByteArrayBuilder
{
public:
  /**
   * Returns a byte array builder object for building up a byte array
   * from various integer size values to represent the underlying bits.
   */
  ByteArrayBuilder();

  void add(char value);
  
  // Add a character (converted to an 8-bit unsigned integer).
  void add(unsigned char value);

  // Add an array of characters (converted to 8-bit unsigned integers).
  void add(unsigned char* values, int numberOfBytes);

  // Adds a value of 1 byte.
  void add(int8_t value);

  // Adds a value of 2 bytes.
  void add(uint16_t value);

  // Adds a value of 2 bytes.
  void add(int16_t value);

  // Adds a value of 4 bytes.
  void add(uint32_t value);

  // Adds a value of 4 bytes.
  void add(int32_t value);

  void add(const ByteArray& byteArray);
  void add(std::string& values);

  ByteArray toByteArray();

  /**
   * Returns the current number of bytes that the length of the
   * Byte Array currently stands at.
   */
  int getNumberOfBytes();

private:
  std::vector<Byte> bytes;

  /**
   * Converts the integer value into 8-bit values dependent on its
   * length in bytes and adds them to the underlying char vector.
   */
  void convertValueToBytes(unsigned int value, int lengthInBytes);
};

#endif