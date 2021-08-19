#include <iostream>
#include <string>
#include "bitmap.h"
#include <string.h>

char* BitmapHeader::toBytes()
{
    int sizeInBytes = 6;
    char* headerPacket = (char*) malloc(sizeInBytes);
    
    strcpy(headerPacket, &this->bitmapSignatureBytes[0]);
    strcat(headerPacket, &this->bitmapSignatureBytes[1]);
    strcat(headerPacket, this->sizeOfBitmapFile);

    std::cout << "Printing in to bytes " << headerPacket << endl;

    return headerPacket;
}