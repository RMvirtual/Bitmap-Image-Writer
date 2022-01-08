#ifndef BYTE_ARRAY_BUILDER_H
#define BYTE_ARRAY_BUILDER_H

#include <cstdint>
#include <vector>

#include "src/common/byte.h"
#include "src/common/byte_array.h"

class ByteArrayBuilder
{
public:
  /**
   * Returns a byte array builder object for building up a byte array
   * from various integer size values to represent the underlying bits.
   */
  ByteArrayBuilder();

  void addValue(char value);

  // Add a character (converted to an 8-bit unsigned integer).
  void addValue(unsigned char value);

  // Add an array of characters (converted to 8-bit unsigned integers).
  void addValues(unsigned char* values, int numberOfBytes);

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
  unsigned char* toBytes();
  ByteArray toByteArray();

  /**
   * Returns the current number of bytes that the length of the
   * Byte Array currently stands at.
   */
  int getNumberOfBytes();

private:
  std::vector<Byte> bytes;

  /**
   * Processes the integer value into bytes and stores them against
   * this object. Requires the length of bytes that the integer should
   * be split up into.
   */
  void processNewValue(int value, int lengthInBytes);

  /**
   * Converts the integer value into 8-bit values dependent on its
   * length in bytes and adds them to the underlying char vector.
   */
  void convertValueToBytes(int value, int lengthInBytes);
  
  /**
   * Converts the underlying vector of bytes into a new char array area
   * of dynamic memory and returns a pointer to it.
   */
  unsigned char* copyArray();
  unsigned char* getEmptyArray();
};

#endif