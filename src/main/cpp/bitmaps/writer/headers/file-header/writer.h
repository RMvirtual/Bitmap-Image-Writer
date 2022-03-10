#pragma once

#include <memory>
#include "src/main/cpp/bitmaps/packet/headers/file-header/header.h"
#include "src/main/cpp/containers/byte-array/byte_array.h"

namespace Bitmaps {
class FileHeaderWriter
{
public:
  FileHeaderWriter();
  ByteArray write(std::shared_ptr<Bitmaps::FileHeader> header);

private:
  ByteArray byteAccumulator;
};}