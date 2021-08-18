#include <cstdint>
#include <fstream>

using namespace std;

class BmpHeader
{
public:
    char bitmapSignatureBytes[2] = {'B', 'M'};
    uint32_t sizeOfBitmapFile = 54 + 786432;
    uint32_t reservedBytes = 0;
    uint32_t pixelDataOffset = 54;
};
