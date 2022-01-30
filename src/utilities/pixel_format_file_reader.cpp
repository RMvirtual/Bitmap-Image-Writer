#include "src/utilities/pixel_format_file_reader.h"
#include "src/utilities/file_system_reader.h"

Utilities::PixelFormatFileReader::PixelFormatFileReader()
{
  // Hardcoding system path here till a reader is developed.
  std::string systemPath {"C://Users/rmvir/Desktop/scc300-Win3D/"};

  Utilities::FileSystemReader files {};
  auto filePath = files.filePath("pixel_formats");

  this->read(systemPath + filePath);
}

std::string Utilities::PixelFormatFileReader::getFormatName(int index)
{  
  auto object = this->json.at(index);
  
  return object.at("name");
}

int Utilities::PixelFormatFileReader::getBitsPerPixel(int index)
{
  auto object = this->json.at(index);
  
  return object.at("bitsPerPixel");
}

std::vector<std::string> Utilities::PixelFormatFileReader::getColours(int index)
{
  auto object = this->json.at(index);

  return object.at("colours"); 
}