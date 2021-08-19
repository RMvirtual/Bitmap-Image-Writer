#include <iostream>
#include <string>
#include "bitmap.h"
#include <string.h>

char* BitmapHeader::toBytes()
{
    char* headerPacket = (char*) malloc(1);
    
    strcpy(headerPacket, &this->bitmapSignatureBytes[0]);

    std::cout << "Printing " << *headerPacket << endl;

    return headerPacket;
}