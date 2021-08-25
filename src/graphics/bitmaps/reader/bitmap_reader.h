#include <string>

class BitmapReader
{
public:
  BitmapReader();
  int getLengthOfPixelPayload(std::string filePath);
  int getSizeOfFile(std::string filePath);
};