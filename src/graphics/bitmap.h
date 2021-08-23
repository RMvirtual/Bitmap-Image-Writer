#include <cstdint>
#include <fstream>

using namespace std;

// 14 bytes total.
class BitmapFileHeader
{
public:
  char bitmapSignatureBytes[2] = {'B', 'M'};
  uint32_t sizeOfBitmapFile = 54 + 786432;
  uint32_t reservedBytes = 0;
  uint32_t pixelDataOffset = 54;

  char* toBytes();
  int getSizeOfHeaderInBytes();
};

class BitmapInfoHeader
{
public:
  uint32_t sizeOfThisHeader = 40;
  int32_t widthInPixels = 512; 
  int32_t heightInPixels = 512; 
  uint16_t numberOfColorPlanes = 1; 
  uint16_t colorDepth = 24; 
  uint32_t compressionMethod = 0;  
  uint32_t rawBitmapDataSize = 0; 
  int32_t horizontalResolutionPixelPerMeter = 3780; 
  int32_t verticalResolutionPixelsPerMeter = 3780; 
  uint32_t colorTableEntries = 0; 
  uint32_t importantColors = 0; 

  char* toBytes();
  int getSizeOfHeaderInBytes();
};

// 14 bytes total.
struct BitmapHeaderStruct
{
  char bitmapSignatureBytes[2] = {'B', 'M'};
  uint32_t sizeOfBitmapFile = 54 + 786432;
  uint32_t reservedBytes = 0;
  uint32_t pixelDataOffset = 54;
};

// 40 bytes total.
struct BitmapInfoHeaderStruct
{
  uint32_t sizeOfThisHeader = 40;
  int32_t widthInPixels = 512; 
  int32_t heightInPixels = 512; 
  uint16_t numberOfColorPlanes = 1; 
  uint16_t colorDepth = 24; 
  uint32_t compressionMethod = 0;  
  uint32_t rawBitmapDataSize = 0; 
  int32_t horizontalResolutionPixelPerMeter = 3780; 
  int32_t verticalResolutionPixelsPerMeter = 3780; 
  uint32_t colorTableEntries = 0; 
  uint32_t importantColors = 0; 
};

// 54 bytes total.

// 3 bytes total.
struct Pixel
{
  uint8_t blue = 255;
  uint8_t green = 255;
  uint8_t red = 100;
};