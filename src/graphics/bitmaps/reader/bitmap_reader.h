#include <string>

class BitmapReader
{
public:
  BitmapReader();
  int getLengthOfPayload(std::string filePath);
  int getSizeOfFile(std::string filePath);
};