#include <iostream>
#include <string>
#include "bitmap.h"
#include <string.h>

char* BitmapHeader::toBytes()
{
    int sizeInBytes = 2;
    char* headerPacket = (char*) malloc(sizeInBytes);
    
    strcpy(headerPacket, &this->bitmapSignatureBytes[0]);
    strcat(headerPacket, &this->bitmapSignatureBytes[1]);

    std::cout << "Printing in to bytes " << headerPacket[1] << endl;

    return headerPacket;
}