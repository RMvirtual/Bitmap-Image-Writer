#include <iostream>
#include <string>
#include "bitmap.h"
#include <string.h>

char* BitmapHeader::toBytes()
{
    int sizeInBytes = 10;
    char* headerPacket = (char*) malloc(sizeInBytes);
    
    strcpy(headerPacket, &this->bitmapSignatureBytes[0]);
    strcat(headerPacket, &this->bitmapSignatureBytes[1]);
    strcat(headerPacket, (char *) &this->sizeOfBitmapFile);
    strcat(headerPacket, (char *) &this->reservedBytes);

    std::cout << "Printing in to bytes " << sizeof(headerPacket) << endl;

    return headerPacket;
}