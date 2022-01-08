#ifndef BYTE_ARRAY_H
#define BYTE_ARRAY_H

#include <vector>
#include "src/common/byte.h"

class ByteArray
{
  public:
    ByteArray();
    void add(std::vector<Byte> bytes);
    Byte operator [](int index);

  private:
    std::vector<Byte> bytes;
};

#endif