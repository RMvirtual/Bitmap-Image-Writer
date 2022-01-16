#ifndef BYTE_ARRAY_H
#define BYTE_ARRAY_H

#include <vector>
#include "src/common/byte-array/byte.h"

class ByteArray
{
  public:
    ByteArray();
    
    void add(const std::vector<Byte>& bytes);
    Byte operator [](int index) const;
    int size() const;
    ByteArray slice(int startIndex, int endIndex) const;

  private:
    std::vector<Byte> bytes;
};

#endif