#include "bitmap.h"

char* BitmapHeader::toBytes()
{
    char* headerPacket;

    headerPacket += this->bitmapSignatureBytes[0];

    return headerPacket;
}