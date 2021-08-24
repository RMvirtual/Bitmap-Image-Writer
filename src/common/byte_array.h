#ifndef BYTE_ARRAY_H
#define BYTE_ARRAY_H

#include <cstdint>

class ByteArrayBuilder
{
public:
  ByteArrayBuilder();
  ~ByteArrayBuilder();

  // Adds a value of 1 byte.
  void addValue(uint8_t value);

  // Adds a value of 2 bytes.
  void addValue(uint16_t value);

  // Adds a value of 4 bytes.
  void addValue(uint32_t value);

  /**
   * Returns a character array pointer towards a copy of the bytes
   * constructed from adding to the ByteArrayBuilder class.
   */ 
  char* toArray();
  
  /**
   * Returns the current number of bytes that the length of the
   * Byte Array currently stands at.
   */
  int getNumberOfBytes();

private:
  char* byteArray;
  int numberOfBytes;

  /**
   * Copies the underlying byte array into a new area of dynamic memory
   * and returns a pointer to it.
   */
  char* copyArray();
  char* copyArray(int sizeToExpandTo);
  char* getEmptyArray(int size);
  void copyArrayContents(char* destinationArray);
  void replaceArray(char* newArray);
  void insertValue(int byteIndex, uint8_t value);
  void insertValue(int byteIndex, uint16_t value);
  void insertValue(int byteIndex, uint32_t value);

};

#endif