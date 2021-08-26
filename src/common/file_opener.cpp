#include "src/common/file_opener.h"
#include <fstream>

using namespace std;

std::string FileOpener::convertFileToString(std::string filePath)
{
  ifstream file(filePath);

  string bytes(
    (std::istreambuf_iterator<char>(file)),
    std::istreambuf_iterator<char>()
  );

  file.close();

  return bytes;   
}
