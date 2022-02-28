#pragma once

#include <cstdint>
#include <string>
#include <vector>

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
    void add(const ByteArray& byteArray);
    void add(const std::string& values);
    void add(const std::vector<uint8_t>& bytes);

    std::vector<uint8_t>::iterator begin();
    std::vector<uint8_t>::iterator end();
    std::vector<uint8_t>::const_iterator begin() const;
    std::vector<uint8_t>::const_iterator end() const;
    uint8_t& operator [](int index);
    uint8_t operator [](int index) const;
    ByteArray slice(int startIndex, int endIndex) const;
    int size() const;

  private:
    std::vector<uint8_t> bytes;
};