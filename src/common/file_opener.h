#ifndef FILE_OPENER_H
#define FILE_OPENER_H

#include <string>

class FileOpener
{
public:
  std::string convertFileToString(std::string filePath);
  int getSizeOfFile(std::string filePath);
};

#endif