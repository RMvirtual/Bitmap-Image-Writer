#include "src/test/cpp/files/json-reader/fixture.h"

void JSONReaderTest::asArrayFile()
{
  this->filePath = {
    "C://Users/rmvir/Desktop/scc300-Win3D/resources/" \
    "test/json-files/array_file.json"
  };

  this->reader = Files::JSONReader::fromArrayFile(this->filePath); 
}

void JSONReaderTest::asObjectFile()
{
  this->filePath = {
    "C://Users/rmvir/Desktop/scc300-Win3D/resources/" \
    "test/json-files/object_file.json"
  };

  this->reader = Files::JSONReader::fromObjectFile(this->filePath);
}

void JSONReaderTest::asNestedObjectsFile()
{
  this->filePath = {
    "C://Users/rmvir/Desktop/scc300-Win3D/resources/" \
    "test/json-files/nested_objects_file.json"
  };

  this->reader = Files::JSONReader::fromObjectFile(this->filePath);
}