#include <cstdint>
#include <fstream>

using namespace std;

// 14 bytes total.
struct BitmapHeader
{
  char bitmapSignatureBytes[2] = {'B', 'M'}; // 2 bytes
  uint32_t sizeOfBitmapFile = 54 + 786432; // 4 byte
  uint32_t reservedBytes = 0; // 4 byte
  uint32_t pixelDataOffset = 54; // 4 byte
};

// 40 bytes total.
struct BitmapInfoHeader
{
  uint32_t sizeOfThisHeader = 40; // 4 byte
  int32_t widthInPixels = 512; // 4 byte
  int32_t heightInPixels = 512; // 4 byte
  uint16_t numberOfColorPlanes = 1; // must be 1? // 2 bytes
  uint16_t colorDepth = 24; // 2 bytes
  uint32_t compressionMethod = 0; // 4 bytes 
  uint32_t rawBitmapDataSize = 0; // generally ignored? // 4 bytes
  int32_t horizontalResolutionPixelPerMeter = 3780; // 4 bytes
  int32_t verticalResolutionPixelsPerMeter = 3780; // 4 bytes
  uint32_t colorTableEntries = 0; // 4 bytes
  uint32_t importantColors = 0; // 4 bytes
};

// 54 bytes total.

// 3 bytes total?
struct Pixel
{
  uint8_t blue = 255;
  uint8_t green = 255;
  uint8_t red = 100;
};