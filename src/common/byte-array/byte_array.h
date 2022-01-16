#ifndef BYTE_ARRAY_H
#define BYTE_ARRAY_H

#include <string>
#include <vector>
#include "src/common/byte-array/byte.h"

class ByteArray
{
  public:
    ByteArray();
    
    void add(const char value);
    void add(const unsigned char value);
    void add(const unsigned char* values, int numberOfBytes);
    void add(const int8_t value);
    void add(const uint16_t value);
    void add(const int16_t value);
    void add(const uint32_t value);
    void add(const int32_t value);
    void add(const Byte& byte);
    void add(const ByteArray& byteArray);
    void add(const std::string& values);
    void add(const std::vector<Byte>& bytes);

    Byte operator [](int index) const;
    ByteArray slice(int startIndex, int endIndex) const;
    int size() const;

  private:
    std::vector<Byte> bytes;
};

#endif