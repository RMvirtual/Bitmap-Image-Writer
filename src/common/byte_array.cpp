

#include "src/common/byte_array.h"

ByteArrayBuilder::ByteArrayBuilder()
{
    this->numberOfBytes = 0;
}

int ByteArrayBuilder::getNumberOfBytes()
{
    return this->numberOfBytes;
}

