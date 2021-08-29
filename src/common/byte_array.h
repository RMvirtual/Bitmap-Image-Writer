#ifndef BYTE_ARRAY_H
#define BYTE_ARRAY_H

#include <cstdint>
#include <vector>

class ByteArrayBuilder
{
public:
  /**
   * Returns a byte array builder object for building up a byte array
   * from various integer size values to represent the underlying bits.
   */
  ByteArrayBuilder();

  // Add a character (converted to an 8-bit unsigned integer).
  void addValue(char value);

  // Add an array of characters (converted to 8-bit unsigned integers).
  void addValues(char* values, int numberOfBytes);

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
  char* copyArray();

  /**
   * Returns a pointer to an empty array of bytes stored in dynamic
   * memory of a specific size. All values initialised to 0.
   */
  char* getEmptyArray(int sizeInBytes);

  /**
   * Copies the contents of this object's underlying vector to a byte
   * array location. Checks to ensure the array is of sufficient size
   * should be performed before using this function.
   */ 
  void copyVectorToArray(char* destinationArray);
};

#endif