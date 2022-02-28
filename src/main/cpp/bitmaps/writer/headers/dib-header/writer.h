#pragma once

#include "src/main/cpp/bitmaps/packet/headers/dib-header/header.h"
#include "src/main/cpp/containers/byte-array/byte_array.h"

namespace Bitmaps {
class DibHeaderWriter
{
public:
  DibHeaderWriter();
  ByteArray write(const Bitmaps::DibHeader& header);

private:
  ByteArray byteAccumulator;
};}